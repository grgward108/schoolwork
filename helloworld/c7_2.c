#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int array[N];
    for (int i = 2; i < N; i++)
    {
        array[i] = i;
    }

    printf("一回目");

    for (int aaa= 0; aaa < N; aaa++){

        printf("%d", aaa);
    }

    printf("\n");
 

    for (int n = 2; n < N; n++)
    {
        if (array[n] != 0)
        {
            for (int m = n + 1; m < N; m++)
            {
                if (array[m] != 0 && array[m] % n == 0)
                {
                    array[m] = 0;
                }
            }
        }

        printf("%d回目: ", n);

        for (int k = 2; k <= N; k++)
        {
            if (array[k] != 0)
            {
                printf("%d, ", array[k]);
            }
        }
        printf("\n");
    }
}

