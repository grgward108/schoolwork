#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} complex;

complex c_add(complex z1, complex z2){

    complex m;
    m.x = z1.x + z2.x;
    m.y = z1.y + z2.y;

    return m;

}

complex c_sub(complex z1, complex z2){

    complex m;
    m.x = z1.x - z2.x;
    m.y = z1.y - z2.y;

    return m;


}

complex c_mul(complex z1, complex z2){
    complex m;

    m.x = z1.x * z2.x - z1.y * z2.y;
    m.y = z1.x * z2.y + z2.x * z1.y;

    return m;

}

complex c_div(complex z1, complex z2){
    complex m;

    m.x = (z1.x * z2.x + z1.y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
    m.y = (z2.x * z1.y - z1.x * z2.y) / (z2.x * z2.x + z2.y * z2.y);

    return m;
    
}

double c_abs(complex z1){

    double m;
    m = sqrt(pow(z1.x,2) + pow(z1.y,2));
    return m;

}

double c_arg(complex z1){
    double result;
    result = atan2(z1.y, z1.x);
    return result;

}

complex c_pow(complex z1, int n){

    complex m;

    double abs_val = c_abs(z1);
    double arg_val = c_arg(z1);
    m.x = pow(abs_val, n) * cos(arg_val * n);
    m.y = pow(abs_val, n) * sin(arg_val * n);

    return m;

}

int main(void){
    complex z1, z2;
    int n;
    printf("enter 2 complex numbers: ");
    scanf("%lf %lf", &z1.x, &z1.y);
    scanf("%lf %lf", &z2.x, &z2.y);

    complex sum = c_add(z1, z2);
    printf("sum is %f + %f i\n", sum.x, sum.y);

    complex diff = c_sub(z1, z2);
    printf("diference is %f + %f i\n", diff.x, diff.y);

    complex multiply = c_mul(z1, z2);
    printf("multiplication is %f + %f i\n", multiply.x, multiply.y);

    complex division = c_div(z1, z2);
    printf("division is %f + %f i\n", division.x, division.y);

    printf("enter an integer: ");
    scanf("%d", &n);

    double absolute = c_abs(z1);
    double argument = c_arg(z1);
    complex power = c_pow(z1, n);

    printf("absolute of z1 is %lf \n", absolute);
    printf("argument of z1 is %lf \n", argument);
    printf("z1 to the power of %d is %lf + %lf i \n", n, power.x, power.y);

}