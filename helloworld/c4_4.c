#include <stdio.h>


int main(void){

int total = 0;
int score;
int frequency = 0;

while (scanf("%d", &score) != EOF){
    total += score;
    frequency += 1;

}

printf("sum: %d, average:%lf, frequency: %d\n", total, (double) total/frequency, frequency);
}