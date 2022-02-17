#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[i + 1];
        for(int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            a[i][j] += a[i + 1][j] > a[i + 1][j + 1] ? a[i + 1][j] : a[i + 1][j + 1];
        }
    }

    printf("%d", a[0][0]);

    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}