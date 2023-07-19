#include <stdio.h>

int main(void){
    int a, x0, m, b;

    a = 2045;
    m = 32768;
    b = 9378;
    x0 = 1;

    int array1[20];
    int array2[20];

    int current = x0;
    for(int i = 0; i < 20; i++){
        current = (current * a) % m;
        int lastdigit = (current * 10) / m;
        /* printf("x_%d is %d, last digit is %d \n", i, current, lastdigit); */
        array1[i] = lastdigit;
    }

    int current2 = x0;
    for(int i  = 0; i < 20; i++){
        current2 = ((current2 * a) + b) % m;
        int lastdigit2 = (current2 * 10) / m;
        /* printf("y_%d is %d, last digit is %d \n", i, current2, lastdigit2); */
        array2[i] = lastdigit2;
    }

    for (int loop= 0; loop < 20; loop++){
        printf("%d, ", array1[loop]);
    }

    printf("\n");

    for (int loop2= 0; loop2 < 20; loop2++){
        printf("%d, ", array2[loop2]);
    }

    printf("\n");







}