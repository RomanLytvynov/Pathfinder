#include "../inc/libmx.h"

char *mx_file_to_str(const char*filename)
{
    int fd = 0;
    char ch;
    int counter = 0;
    fd = open(filename, O_RDONLY);
    if(fd < 0) return NULL;

    while(read(fd, &ch, 1))
        counter++;
    close(fd);
    //if(counter == 0) return NULL;
    char *normal = mx_strnew(counter);
    fd = open(filename, O_RDONLY);
    for (int i = 0; read(fd, &ch, 1); ++i)
    {
        normal[i] = ch;
    }
    close(fd);
    return normal;
}

