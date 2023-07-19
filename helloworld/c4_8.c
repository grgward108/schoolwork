#include <stdio.h>

int main(void){

    int n;
    printf("input number: ");
    scanf("%d", &n);

    if (n > 0){
        for(int i = 0; i < n; i ++){
            for (int j= i; j <= n-1; j ++){
                printf(" ");
            }
            for (int k= 0; k <= i; k ++){
                printf("* ");
            }

            printf("\n");
        }
    }

    if (n < 0){
        n = -n;
        for(int i = n; i >= 0; i --){
            for (int j= n-i; j > 0; j--){
                printf(" ");
            }
            for (int k= i; k > 0; k --){
                printf("* ");
            }

            printf("\n");
        }
    }


}