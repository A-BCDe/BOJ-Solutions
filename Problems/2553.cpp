#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long long x = 1;
    for(int i = 1; i <= n; i++) {
        x *= i;
        while(x % 10 == 0) x /= 10;
        x %= 1000000000;
    }
    printf("%lld", x % 10);
}