#include "../inc/libmx.h"

void mx_del_matrixes(int ****matrixes) {
    if (matrixes == NULL) {
        return;
    }
    int i = 0; 
    while ((*matrixes)[i] != NULL) {
        int j = 0; 
        while ((*matrixes)[i][j] != NULL) {
            free((*matrixes)[i][j]);
            (*matrixes)[i][j] = NULL;
            j++;
        }
        free((*matrixes)[i]);
        (*matrixes)[i] = NULL;
        i++;
    }
    free(*matrixes);
    *matrixes = NULL;
}

