#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }
    t_island *islands = NULL;
    int ***paths = NULL;
    int **matrix = NULL;
    int **matrix_dup = NULL;
    
    init_data(argv[1], &matrix, &paths, &matrix_dup, &islands);
    find_paths(&matrix, paths, matrix_dup, &islands);
    restore_paths(paths, &islands);
    print_paths(matrix_dup, &islands);

    mx_del_matrix(&matrix);
    mx_del_matrix(&matrix_dup);
    mx_del_matrixes(&paths);
    mx_clear_islands(&islands);
    return 0;
}

