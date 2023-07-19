#include <stdio.h>
#include <math.h>

double myexp(double x){
    int nmax = 100;
    double epsilon = 1e-10;
    double term = 1;
    double result = 1;
    int n = 1;

    while (fabs(term) > epsilon && n <= nmax) {
        term *= x/n;
        result += term;
        n++;
    }

    if (n == nmax + 1) {
        printf("Not enough terms for given epsilon\n");
    }

    return result;
}

int main(void){
    double x;
    scanf("%lf", &x);
    printf("%lf\n",myexp(x));
    printf("%lf", exp(x));

}