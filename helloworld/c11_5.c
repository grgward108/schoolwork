#include <stdio.h>
#include <math.h>
#include "c9_1.c"
#include "c9_2.c"


int main(void)
{
    double x1, y1, x2, y2, x3, y3;
    int m,n;
    double a[10], b[10], p_x1, p_y1, r_x1, r_y1;

    printf("x1 y1 = ");
    scanf("%lf %lf", &x1, &y1);

    printf("x2 y2 = ");
    scanf("%lf %lf", &x2, &y2);

    printf("n = ");
    scanf("%d", &n);


    printf("z1 = %.3f %+.3f i\n", x1, y1);
    printf("z2 = %.3f %+.3f i\n", x2, y2);

    c_add(x1, y1, x2, y2, &x3, &y3);
    printf("z1 + z2 = %.3f %+.3f i\n", x3, y3);

    c_sub(x1, y1, x2, y2, &x3, &y3);
    printf("z1 - z2 = %.3f %+.3f i\n", x3, y3);

    c_mul(x1, y1, x2, y2, &x3, &y3);
    printf("z1 * z2 = %.3f %+.3f i\n", x3, y3);

    c_div(x1, y1, x2, y2, &x3, &y3);
    printf("z1 / z2 = %.3f %+.3f i\n", x3, y3);

    printf("c_abs is %lf\n", c_abs(x1, y1));

    printf("c_arg is %lf\n", c_arg(x1, y1));

    c_pow(x1, y1, n, &x3, &y3);
    printf("z1^n = %.3f %+.3f i\n", x3, y3);

    printf("Order of polynominal p(x) ->");

    scanf("%d", &n);

    poly_input(a, n);
    printf("Order of polynominal q(x) ->");
    scanf("%d", &m);

    poly_input(b, m);
    printf("\n");
    printf("p(x)=\n");

    poly_display(a, n);
    printf("\n");
    printf("r(x)=\n");

    rat_display(a, b, n, m);
    printf("\n");

    c_poly_eval(a, n, x1, y1, &p_x1, &p_y1);
    printf("p(x0) = %.3f %+.3f i\n", p_x1, p_y1);
    c_rat_eval(a, b, n, m, x1, y1, &r_x1, &r_y1);
    printf("r(x0) =  %.3f %+.3f i\n", r_x1, r_y1);
    return 0;

}