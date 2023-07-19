#include <stdio.h>

int main(void)
{
    int a,b;
    printf("input a,b\n");
    scanf("%d %d", &a, &b);
    int c,d1, d2,e;
    c = a;
    e = 1;

    while (e != 0){   
        d1 = c%a;
        d2 = c%b;
        e = d1+d2;
        c += 1;
    }

    printf("%d\n", c-1);
}