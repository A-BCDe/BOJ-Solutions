#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int*[n + 1];
    a[0] = new int[3];
    a[0][0] = a[0][1] = a[0][2] = 0;
    for(int i = 1; i <= n; i++) {
        a[i] = new int[3];
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        a[i][0] += min(a[i - 1][1], a[i - 1][2]);
        a[i][1] += min(a[i - 1][0], a[i - 1][2]);
        a[i][2] += min(a[i - 1][0], a[i - 1][1]);
    }
    printf("%d", min(min(a[n][0], a[n][1]), a[n][2]));
    for(int i = 0; i <= n; i++) {
        delete[] a[i];
    }
    delete[] a;
}