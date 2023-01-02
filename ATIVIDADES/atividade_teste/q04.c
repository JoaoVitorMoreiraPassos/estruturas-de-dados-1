#include <stdio.h>
#include <string.h>


void main()
{
    char *v = {"Joao Vitor"};
    int i;
    for (i = 0; i < strlen(v); i ++)
    {
        printf("%c\n",v[i]);
    }
}