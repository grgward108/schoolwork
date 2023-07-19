#include <stdio.h>
#include <stdlib.h>



int main(void){
    int N;
    scanf("%d", &N);
    int array[N];
    int array2[N];


    for(int i = 0; i < N; i++){
        array[i] = rand() % 100;
    }

    for(int i = 0; i < N; i++){
        array2[i] = rand() % 100;
    }

    for(int k = 0; k < N; k++){
        int max = array[k];
        int counter = k;
        for(int m = k+1; m < N; m++){       
            if (array[m] > max){
                max = array[m];
                counter = m;        
            }       
        }
        int temp = array[k];
        array[k] = max;
        array[counter] = temp;
    }

    for(int z = 0; z < N; z++){
        printf("%d, ", array[z]);
    }

    printf("\n");


    for(int m = 0; m < N; m++){
        for(int ll = 0; ll < N-m-1; ll++){
            if (array2[ll + 1] > array2[ll]) {
                int holder = array2[ll];
                array2[ll] = array2[ll+1];
                array2[ll+1] = holder;
            }
        }
    }

    for(int kkk = 0; kkk < N; kkk++){
        printf("%d, ", array2[kkk]);
    }
}