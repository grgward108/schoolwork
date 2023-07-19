#include <stdio.h>

int main(void){

    int n;
    printf("enter a number: ");
    scanf("%d", &n);

    for (int i= 0; i < n; i ++){
        for (int k = 0; k < i; k++){
            printf("0");
        }

        printf("1");

        for (int j= i+1; j < n; j ++){
            printf("0");
        }

        printf("\n");
    
    }
}