#include <stdio.h>

int main()
{
    int i;
    int sum, outgo[12];
    double average;

    for(i = 0; i < 12; i ++){
        printf("%2d's outgo -->", i+1);
        scanf("%d", &outgo[i]);
    }

    sum = 0;
    int max = outgo[0];
    int min = outgo[0];
    for (i = 0; i < 12; i++){
        sum+= outgo[i];
        if(outgo[i] > max){
            max = outgo[i];
        }
        else if(outgo[i] < min){
            min = outgo[i];
        }
    }

    average = (double)sum/12;
    printf("Total outgo: %d\n", sum);
    printf("Average outgo: %f\n", average);
    printf("Max: %d, Min: %d\n", max, min);

}