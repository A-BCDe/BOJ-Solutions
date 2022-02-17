#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int*[n + 1];
    for(int i = 1; i <= n; i++) {
        a[i] = new int[3];
    }
    a[1][0] = 0;
    a[1][1] = a[1][2] = 1;
    for(int i = 2; i <= n; i++) {
        a[i][0] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
        a[i][1] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
        a[i][2] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
    }
    printf("%d", a[n][0]);
}