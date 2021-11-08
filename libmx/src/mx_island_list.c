#include "../inc/libmx.h"

int mx_islands_size(t_island *list) {
    if (list == NULL) {
        return 0;
    }
    int count = 1;
    t_island *l = list;
    while (l->next != NULL) {
        l = l->next;
        count++;
    }
    return count;
}

int find_island_name(t_island *islands, char* name) {
    if (islands == NULL) {
        return -1;
    }
    t_island *i = islands;
    int count = 0;
    while (i != NULL) {
        if (mx_strcmp(i->name, name) == 0) {
            return count;
        }
        i = i->next;
        count++;
    }
    return -1;
}

t_island *find_island_index(t_island *islands, int ind) {
    if (islands == NULL) {
        return NULL;
    }
    t_island *i = islands;
    int count = 0;
    while (count != ind) {
        i = i->next;
        count++;
    }
    return i;
}

t_island *mx_create_island(char *name) {
    t_island *node = malloc(sizeof(t_island));
    node->name = mx_strdup(name);
    node->path = NULL;
    node->next = NULL;
    return node;
}

t_island *mx_push_back_island(t_island **island, char *name) {
    if (*island == NULL) {
        *island = mx_create_island(name);
        return *island;
    }
    t_island *last = mx_create_island(name);
    t_island *end = *island;
    while (end->next != NULL) {
        end = end->next;
    }
    end->next = last;
    return end->next;
}

void mx_clear_islands(t_island **islands) {
    if (islands == NULL) {
        return;
    }
    t_island *l;
    while (*islands != NULL) {
        l = *islands;
        *islands = (*islands)->next;
        t_island *p;
        while (l->path != NULL) {
            p = l->path;
            l->path = l->path->next;
            t_island *is;
            while (p->path != NULL) {
                is = p->path;
                p->path = p->path->next;
                if (is->name != NULL) {
                    free(is->name);
                }
                free(is);
            }
            if (p->name != NULL) {
                free(p->name);
            }
            free(p);
        }
        if (l->name != NULL) {
            free(l->name);
        }
        free(l); 
    }
    islands = NULL;
}

void mx_push_front_island(t_island **island, void *name) {
    t_island *first = mx_create_island(name);
    first->next = *island;
    *island = first;
}

