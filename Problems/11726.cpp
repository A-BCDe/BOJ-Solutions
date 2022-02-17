#include <stdio.h>

int main() {
    int a[1001] = { 1, 1 };
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % 10007;
    }
    printf("%d", a[n]);
}