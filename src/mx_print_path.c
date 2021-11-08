#include "../inc/pathfinder.h"

void print_paths(int **connections, t_island **islands) {
    t_island *cur_list = *islands;
    int cur_island = 0;

    while (cur_list) {
        t_island *pth = cur_list->path; 
        while (pth) {
            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(cur_list->name);
            mx_printstr(" -> ");
            mx_printstr(pth->name);
            mx_printstr("\nRoute: ");
            mx_printstr(cur_list->name);
            t_island *p = pth->path; 
            int count = 0;
            while (p) {
                mx_printstr(" -> ");
                mx_printstr(p->name);
                p = p->next;
                count++;
            }
            p = pth->path;
            mx_printstr("\nDistance: ");
            if (count == 1) {
                mx_printint(connections[cur_island][find_island_name(*islands, p->name)]);
            }
            else {
                int s = connections[cur_island][find_island_name(*islands, p->name)];
                int sum = s;
                mx_printint(s);
                while (p->next) {
                    mx_printstr(" + ");
                    s = connections[find_island_name(*islands, p->name)][find_island_name(*islands, p->next->name)];
                    mx_printint(s);
                    sum += s;
                    p = p->next;
                    count++;
                }
                mx_printstr(" = ");
                mx_printint(sum);
            }
            mx_printstr("\n");
            mx_printstr("========================================\n");
            pth = pth->next;
        }
        cur_island++;
        cur_list = cur_list->next;
    }
}

