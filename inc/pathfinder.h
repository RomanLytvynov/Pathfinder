#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <limits.h>
#include "../libmx/inc/libmx.h"
#include <stdio.h>

void init_data(char *filename, int ***distances, int ****paths, int ***connect, t_island **islands);
void find_paths(int ***distances, int ***paths, int **connections, t_island **islands);
void restore_paths(int ***paths, t_island **islands);
void print_paths(int **connections, t_island **islands);

#endif

