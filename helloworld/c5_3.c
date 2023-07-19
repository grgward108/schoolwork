#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

double function(double x){
    return (2*(x*x*x) + 5*(x*x) - 3*x - 6);
}

double derivative(double x){
    return (6*(x*x) + 10*x- 3);
}

bool check(double x1, double x2){
    double epsilon = 1/(10*10*10*10*10);
    return fabs((x2-x1)/x2) <= epsilon;
}

int main(void){

    int counter = 0;
    double x1, x0;
    x0 = 0;
    scanf("%lf", &x1);

    while ( counter < 100 && !check(x1, x0))
    {

        printf("%lf\n", x1);
        double holder = x1;
        x1 = x1 - (function(x1)/ derivative(x1));
        x0 = holder;
        counter += 1;


    }





}