#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int*[n + 1];
    a[0] = new int[2]();
    for(int i = 1; i <= n; i++) {
        a[i] = new int[2]();
        int s;
        scanf("%d", &s);
        if(i == 1) {
            a[1][0] = s;
        }
        else if(i == 2) {
            a[2][0] = s;
            a[2][1] = a[1][0] + s;
        }
        else {
            a[i][0] = max(a[i - 2][0], a[i - 2][1]) + s;
            a[i][1] = a[i - 1][0] + s;
        }
    }
    printf("%d", max(a[n][0], a[n][1]));
}