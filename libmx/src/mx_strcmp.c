#include "../inc/libmx.h"

int mx_strcmp(const char*s1, const char*s2)
{
    if(mx_strlen(s1) > mx_strlen(s2))
    {
        for(int i = 0; i < mx_strlen(s2)+1; i++)
        {
            if(s1[i] == s2[i]) continue;
            else return (int)s1 - (int)s2;
        }
        return 0;
    }
    else if(mx_strlen(s1) < mx_strlen(s2))
    {
        for(int i = 0; i < mx_strlen(s1)+1; i++)
        {
            if(s1[i] == s2[i]) continue;
            else return (int)s1 - (int)s2;
        }
        return 0;
    }
    else
    {
        for(int i = 0; i < mx_strlen(s1); i++)
        {
            if(s1[i] == s2[i]) continue;
            else return (int)s1 - (int)s2;
        }
        return 0;
    }
}

