#include <stdio.h>

int maiorMenor(int n1, int n2)
{
    if(n1 > n2)
    {
        return 1;
    }
    if(n1 < n2)
    {
        return -1;
    }
    if (n1 == n2)
    {
        return 0;
    }
}