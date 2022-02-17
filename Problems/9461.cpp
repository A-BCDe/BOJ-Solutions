#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        if(n < 4) {
            printf("1\n");
            continue;
        }
        if(n < 6) {
            printf("2\n");
            continue;
        }
        auto a = new long long[n + 1];
        a[1] = a[2] = a[3] = 1;
        a[4] = a[5] = 2;
        for (int i = 6; i <= n; i++) {
            a[i] = a[i - 1] + a[i - 5];
        }
        printf("%lld\n", a[n]);
        delete[] a;
    }
}