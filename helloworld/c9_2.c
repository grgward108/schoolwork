#include <stdio.h>
#include <math.h>

void poly_input(double a[10], int n)
{
    int i;
    for(i=n;i>=0;i--){
        printf("a_%d->", i);
        scanf("%lf", &a[i]);
    }
}

void poly_display(double a[10], int n)
{
    int i;
    for(i=n; i>0; i--){
        printf("%+.2fx^%d", a[i], i);
    }
    printf("%+.2f\n", a[0]);
}

void rat_display(double a[10], double b[10], int n, int m)
{
    int i;
    poly_display(b, m);
    for(i=0;i<=n;i++){
        printf("--------");
    }
    printf("\n");
    poly_display(a, n);
}

void c_poly_eval(double a[10], int n, double x0, double y0, double *p_x0, double *p_y0)
{
    int i;
    double abs_val = c_abs(x0, y0);
    double arg_val = c_arg(x0, y0);
    for (i=n; i>=0; i--) {   
        *p_x0 += a[i] * (pow(abs_val, i) * cos(arg_val * i));
        *p_y0 += a[i] * (pow(abs_val, i) * sin(arg_val * i));
    }
}

void c_rat_eval(double a[10], double b[10], int n, int m, double x0, double y0, double *r_x0, double *r_y0)
{
    int i;
    double abs_val = c_abs(x0, y0);
    double arg_val = c_arg(x0, y0);
    double holderpx0, holderpy0, holderqx0, holderqy0;

    for (i=n; i>=0; i--) {   
        holderpx0 += a[i] * (pow(abs_val, i) * cos(arg_val * i));
        holderpy0 += a[i] * (pow(abs_val, i) * sin(arg_val * i));
    }

    for (i=m; i>=0; i--) {   
        holderqx0 += b[i] * (pow(abs_val, i) * cos(arg_val * i));
        holderqy0 += b[i] * (pow(abs_val, i) * sin(arg_val * i));
    }

    c_div(holderpx0, holderpy0, holderqx0, holderqy0, r_x0, r_y0);

}


// int main(void)
// {
//     int m,n;
//     double a[10], b[10], x0, y0, p_x0, p_y0, r_x0, r_y0;
//     printf("Order of polynominal p(x) ->");
//     scanf("%d", &n);
//     poly_input(a, n);
//     printf("Order of polynominal q(x) ->");
//     scanf("%d", &m);
//     poly_input(b, m);
//     printf("\n");
//     printf("p(x)=\n");
//     poly_display(a, n);
//     printf("\n");
//     printf("r(x)=\n");
//     rat_display(a, b, n, m);
//     printf("\n");
//     printf("x0->");
//     scanf("%lf", &x0);
//     printf("\n");
//     printf("x0 = %lf\n", x0);
//     printf("y0->");
//     scanf("%lf", &y0);
//     printf("\n");
//     printf("y0 = %lf\n", y0);  
//     c_poly_eval(a, n, x0, y0, &p_x0, &p_y0);
//     printf("p(x0) = %.3f %+.3f i\n", p_x0, p_y0);
//     c_rat_eval(a, b, n, m, x0, y0, &r_x0, &r_y0);
//     printf("r(x0) =  %.3f %+.3f i\n", r_x0, r_y0);
//     return 0;
// }