#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));
    int arr[10];

    for(int i = 0; i < 10; i ++)
    {
        arr[i] = rand() % 100; // Generates random numbers between 0 and 99
    }

    printf("Unsorted array: \n");
    printArray(arr, 10);

    quickSort(arr, 0, 9);

    printf("Sorted array: \n");
    printArray(arr, 10);
}
