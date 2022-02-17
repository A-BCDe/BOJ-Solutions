#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int[n + 1];
    a[0] = a[1] = 1;
    for(int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % 15746;
    }
    printf("%d", a[n]);
    delete[] a;
}