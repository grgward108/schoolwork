#include <stdio.h>

int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
        int holder = a;
        a = b;
        b = holder;
    }
    int multiply = a * b;
    int gcd = GCD(a, b);
    printf("GCD: %d, LCM: %d\n", gcd, multiply / gcd);

    return 0;
}
