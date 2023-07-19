#include <stdio.h>

int main(void)
{
    int *ip;
    int num;  
    ip = &num;
    
    printf("input an integer -> ");
    scanf("%d", ip);
    printf("Square of the integer %d is %d\n", *ip, *ip * *ip);

    return 0;
}