#ifndef LIBMX
#define LIBMX

#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h>
#include <stdbool.h>
#include <malloc/malloc.h>

//Extra functions
bool mx_isalpha(int c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void swap(void **s1, void **s2);
void mx_printerr(const char *s);
void mx_del_matrix(int ***matrix);
void mx_del_matrixes(int ****matrixes);

// Utils pack
void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int num);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
int mx_atoi(const char *s);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char** arr, int size, const char *s, int *count);
int mx_bubble_sort(char** arr, int size);
int mx_quicksort(char **arr, int left, int right);


// String pack
int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);


// Memory pack
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

// List pack
typedef struct s_island {
    char *name;
    struct s_island *path;
    struct s_island *next;
}               t_island;

int mx_islands_size(t_island *list);
int find_island_name(t_island *islands, char* name);
t_island *mx_create_island(char *name);
t_island *mx_push_back_island(t_island **island, char *name);
void mx_clear_islands(t_island **islands);
void mx_push_front_island(t_island **island, void *name);
t_island *find_island_index(t_island *islands, int ind);



#endif

