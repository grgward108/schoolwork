#include <stdio.h>

int main(void){

    int a,b;
    printf("input a,b\n");
    scanf("%d %d", &a, &b);

    int m, n, r;

    m = a;
    n = b;
    r= m %n;

    do {   
        m = n;
        n = r;
        r = m % n;
    }while( r!= 0);

    printf("%d\n", n);


}