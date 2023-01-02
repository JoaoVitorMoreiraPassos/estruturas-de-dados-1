#include <stdio.h>
int main(){
int i = 99, j;
int *p;
p = &i;
j = *p + 100;
printf("%d",j);
}