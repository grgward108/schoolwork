#include <stdio.h>

int main(void){
    int a1, a2, n;
    scanf("%d %d %d", &a1, &a2, &n);

    int m = a1;
    int l = a2;
    int c;

    for (int i = 2; i<n; i++)
    {  
        c = m + l;
        l = m;
        m = c;
        printf("%d\n", m);
    }

    

}