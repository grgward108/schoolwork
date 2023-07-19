#include <stdio.h>
#include <math.h>

void poly_read(double a[], int n)
{
    for(int m = 0; m < n; m++)
    {
        printf("a[%d] -> ", m);
        scanf("%lf", &a[m]);
    }
}

void poly_print(double a[], int n)
{
    for(int m = n-1; m >= 0; m--)
    {
        if (m == 0) {
            printf("%lf", a[m]);
        } else if (m == 1) {
            printf("%lf*x + ", a[m]);
        } else {
            printf("%lf*x^%d + ", a[m], m);
        }
    }
    printf("\n");
}

void poly_diff(double a[], int n, double b[])
{
    for(int m = 0; m < n - 1; m++)
    {
        b[m] = a[m+1] * (m+1);
    }
}

void poly_int(double a[], int n, double c[])
{
    c[0] = 0;
    for (int m = 1; m < n+1; m++)
    {
        c[m] = a[m-1] / m;
    }
}

double poly_eval(double a[], int n, double x0)
{
    double eval = 0.0;
    for (int m = 0; m < n; m ++){
        eval += a[m] * pow(x0, m);
    }
    return eval;
}

int main()
{
    int n;
    double x0;

    printf("n, x0?\n");
    scanf("%d %lf", &n, &x0);

    n = n + 1; 
    double A[n], B[n], C[n+1];

    poly_read(A,n);
    printf("\nf(x) = ");
    poly_print(A,n);

    printf("\ng(x) = f'(x)= ");
    poly_diff(A,n,B);
    poly_print(B, n-1);

    printf("\nh(x) = int_f(x)=");
    poly_int(A,n,C);
    poly_print(C, n+1);

    printf("\n");
    printf("f(%.1f)=%.3f\n", x0, poly_eval(A,n,x0));
    printf("g(%.1f)=%.3f\n", x0, poly_eval(B,n-1,x0));
    printf("h(%.1f)=%.3f\n", x0, poly_eval(C,n+1,x0));
    
    return 0;
}
