#include <stdio.h>
#include <math.h>

typedef struct{
    double xaxis;
    double yaxis;
}point;

double length(point a, point b){
    double length_xaxis = b.xaxis - a.xaxis;
    double length_yaxis = b.yaxis - a.yaxis;
    double length = sqrt(pow(length_xaxis, 2) + pow(length_yaxis, 2));

    return length;
}

double area(point a, point b, point c){

    double length1 = length(a, b);
    double length2 = length(b, c);
    double length3 = length(a, c);

    double s = (length1 + length2 + length3) / 2;

    double area = sqrt((s)*(s-length1)*(s-length2)*(s-length3));

    return area;


}

int main(void){
    point a, b, c;

    printf("enter 3 points: \n");

    scanf("%lf %lf", &a.xaxis, &a.yaxis);
    scanf("%lf %lf", &b.xaxis, &b.yaxis);
    scanf("%lf %lf", &c.xaxis, &c.yaxis);


    double lengtha = length(a, b);
    double lengthb = length(a, c);
    double lengthc = length(b, c);

    printf("lengths are %lf, %lf, %lf\n", lengtha, lengthb, lengthc);

    double result = area(a, b, c);
    printf("area is %lf\n", result);

}