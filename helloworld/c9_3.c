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


void c_rat_eval(double a[10], double b[10], int n, int m, double x0, double y0, double *r_x0, double *r_y0)
{
    int i;
    double abs_val = c_abs(x0, y0);
    double arg_val = c_arg(x0, y0);
    double holderpx0 = 0.0, holderpy0 = 0.0, holderqx0 = 0.0, holderqy0 = 0.0;

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


int main(void)
{
    int m, n, i, j;
    double r_x0, r_y0;
    double a[10], b[10], omega, g_x, g_y, gain, arg;
    printf("Order of polynominal p(x) ->");
    scanf("%d", &n);
    poly_input(a, n);
    printf("Order of polynominal q(x) ->");
    scanf("%d", &m);
    poly_input(b, m);

    FILE *fp;
    fp = fopen("data.csv", "w");
    for(i=-2; i<2; i++){
        for(j=0; j<=899; j++){
            omega = (1+(double)j/100.0) * pow(10, i);
            g_x = 0; 
            g_y = omega;
            c_rat_eval(a, b, n, m, g_x, g_y, &r_x0, &r_y0);
            gain = 20 * log10(sqrt(pow(r_x0,2) + pow(r_y0, 2)));
            arg = c_arg(r_x0, r_y0);
            fprintf(fp, "%10f,%10f,%10f\n", omega, gain, arg);
        }
    }
    fclose(fp);
    return 0;
}
