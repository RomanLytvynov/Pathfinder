#include "../inc/libmx.h"

void mx_del_matrix(int ***matrix) {
    if (matrix == NULL) {
        return;
    }
    int i = 0; 
    while ((*matrix)[i] != NULL) {
        free((*matrix)[i]);
        (*matrix)[i] = NULL;
        i++;
    }
    free(*matrix);
    *matrix = NULL;
}

