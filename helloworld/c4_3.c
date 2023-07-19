#include <stdio.h>

int main(void) {

    int i, arr[10];
    printf("enter 10 elements: \n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        getchar();
    }

    int b = 0;
    int max = arr[0];
    int min = arr[0];

    do {
        if (arr[b] > max) {
            max = arr[b];
        }
        
        if (arr[b] < min) {
            min = arr[b];
        }
        
        b += 1;
    } while (b < 10);

    printf("max:%d, min:%d\n", max, min);
    return 0;
}
