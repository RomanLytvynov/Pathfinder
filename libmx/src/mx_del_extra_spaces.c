#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *str_del = NULL;
    char *temp = NULL;
    int i = 0;
    int j = 0;
    if (!str) {
        return NULL;
    }
    str_del = mx_strnew(mx_strlen(str));
    while (str[i]) {
        if (!(mx_isspace(str[i]))) {
            str_del[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            str_del[j] = ' ';
            j++;
        }
        i++;
    }
    temp = mx_strtrim(str_del);
    mx_strdel(&str_del);
    return temp;
}

