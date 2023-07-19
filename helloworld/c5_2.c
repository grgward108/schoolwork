#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double function(double x){
    return (x*x - 10*(sin(x)) - 5);
}

bool checker(double x2, double x1){
    double epsilon = 1/(10*10*10*10*10);
    return fabs((x2-x1)/x2) <= epsilon;
}

int main(void){
    int counter = 0;
    double xl0, xr0;
    scanf("%lf %lf", &xl0, &xr0);
    double xm1 = ((xl0 + xr0) / 2);
    double xm0 = 0;


    while (counter < 100 && !checker(xm1, xm0)) {
        
        double holder1 = function(xl0);
        double holder2 = function(xr0);

        printf("x_%d is %f\n", counter, xm1);

        if ((holder1 * function(xm1)) < 0){
            xr0 = xm1;
        }

        else if ((holder1 * function(xm1)) > 0){
            xl0 = xm1;
        }

        else if (function(xm1) == 0) {
            printf("solution is %f", xm1);
            printf("f(x_%d) = %f", counter, function(xm1));
            break;
        }

        double foo = xm1;
        xm1 = ((xl0 + xr0) / 2);
        xm0 = foo;
        counter = counter + 1;
    }

    return 0;
}