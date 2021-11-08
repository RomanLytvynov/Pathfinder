#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int num = 0;
    while (*str != '\n') {
        if (mx_isdigit(*str)) {
            num *= 10;
            num += (int)*str - 48;
        }
        else {
            return 0;
        }
        str++;
    }
    return num;
}

