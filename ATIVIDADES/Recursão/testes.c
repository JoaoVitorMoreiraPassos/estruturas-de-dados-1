#include <stdio.h>


int fatorial(int n)
{
    if(n <= 0){
        return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}


void main()
{
    int n = 17;
    printf("fatorial: %d\n",fatorial(n));
}