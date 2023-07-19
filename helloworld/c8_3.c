#include <stdio.h>

int main(void)
{
    int a = 100, b = 105, *ptr;
    printf("a = %d, b= %d\n", a, b);

    ptr = &b;
    printf("a = %d, b= %d, *ptr = %d\n", a, b, *ptr);

    a = *ptr;
    printf("a = %d, b= %d, *ptr = %d\n", a, b, *ptr);

    *ptr = 110;
    printf("a = %d, b= %d, *ptr = %d\n", a, b, *ptr);

    b = 110;
    printf("a = %d, b= %d, *ptr = %d\n", a, b, *ptr);

    ptr = &a;
    printf("a = %d, b= %d, *ptr = %d\n", a, b, *ptr);


}