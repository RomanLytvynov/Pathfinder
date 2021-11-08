#include "../inc/pathfinder.h"

static void double_path(t_island **islands, t_island *pth, int next, int count) {
    t_island *p = pth;
    for (int m = 0; m < count; m++) {
        p = p->next;
    }
    t_island *buff = NULL;
    if (p->next != NULL) {
        buff = p->next;
    }
    p->next = mx_create_island(pth->name);
    t_island *isl = pth->path;
    while(isl) {
        mx_push_back_island(&(p->next->path), isl->name);
        isl = isl->next;
    }
    t_island *nxt = find_island_index(*islands, next);
    mx_push_front_island(&(p->next->path), nxt->name);
    if (buff) {
        p->next->next = buff;
    }
}

void restore_paths(int ***paths, t_island **islands) {
    int num_isl = mx_islands_size(*islands);
    t_island *isl = *islands;
    for (int curc_island = 0; curc_island < num_isl; curc_island++) {
        for (int j = curc_island; j < num_isl; j++) {
            if (j == curc_island) {
                continue;
            }
            int count = 0;
            for (int m = 0; m < num_isl; m++) {
                count += paths[curc_island][j][m];
            }
            if (count == 0) {
                continue;
            }
            t_island *p = find_island_index(*islands, j);
            p = mx_push_back_island(&(isl->path), p->name);
            while (p != NULL) {
                int next;
                int dp = 0;
                if (p->path == NULL) {
                    next = j;
                }
                else {
                    next = find_island_name(*islands, p->path->name);
                    if (next == curc_island) {
                        t_island *isl = p->path;
                        p->path = p->path->next;
                        free(isl->name);
                        free(isl);
                        p = p->next;
                        continue;
                    }
                    dp = 1;
                }
                while (true) {
                    count = 0;
                    if (dp == 0) {
                        t_island *i = find_island_index(*islands, next);
                        mx_push_front_island(&(p->path), i->name);
                    }
                    dp = 0;
                    int nxt = -1;
                    for (int m = 0; m < num_isl; m++) {
                        if (paths[curc_island][next][m]) {
                            if (nxt == -1) {
                                nxt = m;
                            }
                            else {
                                double_path(islands, p, m, count);
                                count++;
                            }
                        }
                    }
                    next = nxt;
                    if (next == curc_island || next == -1) {
                        break;
                    }
                }
                p = p->next;
            }
        } 
        isl = isl->next;
    }
}

