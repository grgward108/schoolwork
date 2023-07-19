#include <stdio.h>
#include <math.h>

void c_add(double x1, double y1, double x2, double y2, double *x3, double *y3)
{
    *x3 = x1 + x2;
    *y3 = y1 + y2;
}

void c_sub(double x1, double y1, double x2, double y2, double *x3, double *y3)
{
    *x3 = x1 - x2;
    *y3 = y1 - y2;
}

void c_mul(double x1, double y1, double x2, double y2, double *x3, double *y3)
{
    *x3 = x1 * x2 - y1 * y2;
    *y3 = x1 * y2 + x2 * y1;
}

void c_div(double x1, double y1, double x2, double y2, double *x3, double *y3)
{
    *x3 = (x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2);
    *y3 = (x2 * y1 - x1 * y2) / (x2 * x2 + y2 * y2);
}

double c_abs(double x1, double y1)
{
    return sqrt(x1 * x1 + y1 * y1);
}

double c_arg(double x1, double y1)
{
    return atan2(y1, x1);
}

void c_pow(double x1, double y1, int n, double *x3, double *y3)
{
    double abs_val = c_abs(x1, y1);
    double arg_val = c_arg(x1, y1);
    *x3 = pow(abs_val, n) * cos(arg_val * n);
    *y3 = pow(abs_val, n) * sin(arg_val * n);
}

// int main()
// {
//     double x1, y1, x2, y2, x3, y3;
//     int n;

//     printf("x1 y1 = ");
//     scanf("%lf %lf", &x1, &y1);

//     printf("x2 y2 = ");
//     scanf("%lf %lf", &x2, &y2);

//     printf("n = ");
//     scanf("%d", &n);

//     printf("z1 = %.3f %+.3f i\n", x1, y1);
//     printf("z2 = %.3f %+.3f i\n", x2, y2);

//     c_add(x1, y1, x2, y2, &x3, &y3);
//     printf("z1 + z2 = %.3f %+.3f i\n", x3, y3);

//     c_sub(x1, y1, x2, y2, &x3, &y3);
//     printf("z1 - z2 = %.3f %+.3f i\n", x3, y3);

//     c_mul(x1, y1, x2, y2, &x3, &y3);
//     printf("z1 * z2 = %.3f %+.3f i\n", x3, y3);

//     c_div(x1, y1, x2, y2, &x3, &y3);
//     printf("z1 / z2 = %.3f %+.3f i\n", x3, y3);

//     printf("c_abs is %lf\n", c_abs(x1, y1));

//     printf("c_arg is %lf\n", c_arg(x1, y1));

//     c_pow(x1, y1, n, &x3, &y3);
//     printf("z1^n = %.3f %+.3f i\n", x3, y3);

//     return 0;
// }
