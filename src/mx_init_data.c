#include "../inc/pathfinder.h"

static void print_errors(int error_num, char *filename, char **str, int number_of_line, int ***distances, int ****paths, char **isalnd_name, t_island **islands) 
{
    if(error_num == 1)
    {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    else if(error_num == 2)
    {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(0);
    }
    else if(error_num == 3)
    {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(number_of_line));
        mx_printerr(" is not valid\n");
    }
    else if(error_num == 4)
    {
        mx_printerr("error: invalid number of islands\n");
    }
    else if(error_num == 5)
    {
        mx_printerr("error: duplicate bridges\n");
    }
    else
    {
        mx_printerr("error: sum of bridges lengths is too big\n");
    }
    
    if (str != NULL) {
        free(*str);
        *str = NULL;
    }
    mx_del_matrix(distances);
    mx_del_matrixes(paths);
    if (isalnd_name != NULL) {
        free(*isalnd_name);
        *isalnd_name = NULL;
    }
    mx_clear_islands(islands);
    exit(0);
}

void init_data(char *filename, int ***distances, int ****paths, int ***connect, t_island **islands) {
    int fd = open(filename, O_RDONLY, 0);
    if (fd == -1) {
        print_errors(1, filename, NULL, 0, NULL, NULL, NULL, NULL);
    }
    close(fd);

    char *str = mx_file_to_str(filename);       
    if (str == NULL || str[0] == '\0') {
        print_errors(2, filename, NULL, 0, NULL, NULL, NULL, NULL);
    }

    int number_of_islands = mx_atoi(str);
    if (number_of_islands == 0) {
        print_errors(3, NULL, &str, 1, NULL, NULL, NULL, NULL);
    }

//---------------------------------------------------------------------------------------------// 
    *distances = (int **)malloc(sizeof(int *) * (number_of_islands + 1));  
    for (int j = 0; j < number_of_islands; j++) {
        (*distances)[j] = (int *)malloc(sizeof(int) * number_of_islands);
        for (int k = 0; k < number_of_islands; k++) {
            if (k == j) {
                (*distances)[j][k] = 0;
            }
            else {
                (*distances)[j][k] = -1;
            }
        }
    }
//---------------------------------------------------------------------------------------------// 
    (*distances)[number_of_islands] = NULL; 
    *paths = (int ***)malloc(sizeof(int **) * (number_of_islands + 1));    
    for (int j = 0; j < number_of_islands; j++) {
        (*paths)[j] = (int **)malloc(sizeof(int *) * (number_of_islands + 1));
        for (int k = 0; k < number_of_islands; k++) {
            (*paths)[j][k] = (int *)malloc(sizeof(int) * number_of_islands);
            for (int m = 0; m <number_of_islands; m++) {
                (*paths)[j][k][m] = 0;
            }
            (*paths)[j][number_of_islands] = NULL; 
        }
    }
    (*paths)[number_of_islands] = NULL; 
//---------------------------------------------------------------------------------------------//    
    int i = 0;
    while (str[i] != '\n') {
        i++;
    }
    i++;
    int number_of_line = 2;
    char *isalnd_name = NULL;              
    bool duplicate = false;
    while (str[i] != '\0') {
        while(str[i] != '-') {
            if (!mx_isalpha(str[i])) {
                print_errors(3, NULL, &str, number_of_line, distances, paths, &isalnd_name, islands);
            }
            char temp[] = {str[i], '\0'};
            isalnd_name = mx_strjoin(isalnd_name, temp);
            i++;
        }
        i++;
        int i1 = find_island_name(*islands, isalnd_name);
        if (i1 == -1) {
            mx_push_back_island(islands, isalnd_name);
            i1 = mx_islands_size(*islands) - 1;
        }
        if (isalnd_name != NULL) {
            free(isalnd_name);
            isalnd_name = NULL;
        }
        while(str[i] != ',') {
            if (!mx_isalpha(str[i])) {
                print_errors(3, NULL, &str, number_of_line, distances, paths, &isalnd_name, islands);
            }
            char temp[] = {str[i], '\0'};
            isalnd_name = mx_strjoin(isalnd_name, temp);
            i++;
        }
        i++;
        int i2 = find_island_name(*islands, isalnd_name);
        if (i1 == i2) {
            print_errors(3, NULL, &str, number_of_line, distances, paths, &isalnd_name, islands);
        }
        if (i2 == -1) {
            mx_push_back_island(islands, isalnd_name);
            i2 = mx_islands_size(*islands) - 1;
        }
        if (isalnd_name != NULL) {
            free(isalnd_name);
            isalnd_name = NULL;
        }
        int d = mx_atoi(&(str[i]));
        if (d == 0) {
            print_errors(3, NULL, &str, number_of_line, distances, paths, &isalnd_name, islands);
        }
        if (i1 < number_of_islands && i2 < number_of_islands) {
            if ((*distances)[i1][i2] != -1) {
                duplicate = true;
            }
            (*distances)[i1][i2] = d;
            (*distances)[i2][i1] = d;
        }
        while (str[i] != '\n') {
            i++;
        }
        i++;
        number_of_line++;
    }
    if (mx_islands_size(*islands) != number_of_islands) {
        print_errors(4, NULL, &str, 0, distances, paths, NULL, islands);
    }
    if (duplicate) {
        print_errors(5, NULL, &str, 0, distances, paths, NULL, islands);
    }
    int sum = 0;
    for (int j = 0; j < number_of_islands; j++) {
        for (int k = 0; k < number_of_islands; k++) {
            if ((*distances)[j][k] == -1) {
                continue;
            }
            if (INT_MAX - (*distances)[j][k] > sum) {
                sum += (*distances)[j][k];
            }
            else {
                print_errors(6, NULL, &str, 0, distances, paths, NULL, islands);
            }
        }
    }
    if (str != NULL) {
        free(str);
        str = NULL;
    }
    *connect = (int **)malloc(sizeof(int *) * (number_of_islands + 1));   
    for (int j = 0; j < number_of_islands; j++) {
        (*connect)[j] = (int *)malloc(sizeof(int) * number_of_islands);
        for (int k = 0; k < number_of_islands; k++) {
            (*connect)[j][k] = (*distances)[j][k];
        }
    }
    (*connect)[number_of_islands] = NULL; 
}

