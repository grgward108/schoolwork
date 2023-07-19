#include <stdio.h>

int main(void){
    int a, c;
    double b;
    printf("元金：");
    scanf("%d", &a);
    printf("年利率：");
    scanf("%lf", &b);
    printf("預金期間:");
    scanf("%d", &c);

    double curr = a;

    for (int i=0; i<c; i ++){

        curr = curr * (1 + b);
        printf("year %d, total %lf\n", (i+1), curr);

    }

}