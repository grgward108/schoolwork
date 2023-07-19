#include <stdio.h>
#include <stdlib.h>



int myrand(int x){
      int a = 2045;
      int m = 32768;
      int b = 9378;
      int rand1 = ((a*x)+b) %m;

      return rand1;
      }

int main(void){
    int m = 32768;
    int inside = 0;
    int for_x= 1;
    int for_y = 1;
    int inside_rand = 0;

    for(int i=1; i <= 100000; i++){
        for_x = myrand(for_x);
        for_y = myrand(for_x);
        double to_test_x = (double) for_x /(double) m;
        double to_test_y = (double) for_y/ (double) m;


        double rand_x = (double)rand()/ (double)(RAND_MAX);
        double rand_y = (double)rand()/ (double)(RAND_MAX);

        if ((rand_x*rand_x) + (rand_y*rand_y) <= 1){
            inside_rand++;

        }

        if (i % 1000 == 0){
            printf("nが1000で割り切れる時に表示\n");
        }

        if (((to_test_x) * (to_test_x) + (to_test_y) * (to_test_y)) <= 1){
            inside ++;
        }

        for_x = for_y;


    }

    printf("線形合同法%lf\n", (double) inside * 4/ (double) 100000);
    printf("c_library_random%lf", (double)inside_rand * 4/ (double) 100000);
}