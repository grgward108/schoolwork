#include <stdio.h>
#define N 10

void mat_read(double a[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
}

void mat_print(double a[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}

void mat_add(double a[N][N], double b[N][N], double c[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void mat_product(double a[][N], double b[][N], double c[][N], int n, int m, int r) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int n, m, r;
    double A[N][N], B[N][N], C[N][N], D[N][N];

    printf("n m r?\n");
    scanf("%d %d %d", &n, &m, &r);

    printf("Matrix A\n");
    mat_read(A, n, m);
    mat_print(A, n, m);

    printf("Matrix B\n");
    mat_read(B, n, m);
    mat_print(B, n, m);

    printf("Matrix C\n");
    mat_read(C, m, r);
    mat_print(C, m, r);

    printf("Matrix A + B\n");
    mat_add(A, B, D, n, m);
    mat_print(D, n, m);

    printf("Matrix A * C\n");
    mat_product(A, C, D, n, m, r);
    mat_print(D, n, r);

    return 0;
}
