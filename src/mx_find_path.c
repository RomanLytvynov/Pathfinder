#include "../inc/pathfinder.h"

static int find_min_distance(int cur_island, int number_of_islands, int ***distances, int *visited) 
{
    int min = INT_MAX;
    int ind_min = -1, j = 0;
    while(j < number_of_islands)
    {
        if (visited[j] || (*distances)[cur_island][j] == -1) {
            j++;
            continue;
        }
        if ((*distances)[cur_island][j] < min) {
            min = (*distances)[cur_island][j];
            ind_min = j;
        }
        j++;
    }
    return ind_min;
}

void find_paths(int ***distances, int ***paths, int **connections, t_island **islands) {
    int number_of_islands = mx_islands_size(*islands);
    int *visited = (int *)malloc(sizeof(int) * number_of_islands);  
    for (int cur_island = 0; cur_island < number_of_islands; cur_island++) {
        for (int j = 0; j < number_of_islands; j++) {
            visited[j] = 0;
        }
        while (1) {
            int ind_min = find_min_distance(cur_island, number_of_islands, distances, visited);
            if (ind_min == -1) {
                break;
            }
            for (int j = 0; j < number_of_islands; j++) {
                if (connections[ind_min][j] > 0 && !visited[j]) {
                    if ((*distances)[cur_island][j] > (*distances)[cur_island][ind_min] + connections[ind_min][j] || (*distances)[cur_island][j] == -1) {
                        (*distances)[cur_island][j] = (*distances)[cur_island][ind_min] + connections[ind_min][j];
                    }
                }
            }
            visited[ind_min] = 1;
        }
        for (int j = 0; j < number_of_islands; j++) {
            if (j == cur_island) {
                continue;
            }
            for (int k = 0; k < number_of_islands; k++) {
                if (connections[j][k] > 0) {
                    if ((*distances)[cur_island][j] - connections[j][k] == (*distances)[cur_island][k]) {
                        paths[cur_island][j][k] = 1;
                    }
                }
            }
        }
    }
    free(visited);
    visited = NULL;
}

