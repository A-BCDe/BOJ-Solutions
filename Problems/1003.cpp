#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        if(n == 0) {
            printf("1 0\n");
            continue;
        }
        if(n == 1) {
            printf("0 1\n");
            continue;
        }
        auto a = new int[n + 1];
        a[0] = a[1] = 1;
        for(int i = 2; i < n; i++) {
            a[i] = a[i - 1] + a[i - 2];
        }
        printf("%d %d\n", a[n - 2], a[n - 1]);
    }
}