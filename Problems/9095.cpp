#include <stdio.h>
int get(int *a, int n) {
    if(a[n] != 0) return a[n];
    return get(a, n - 1) + get(a, n - 2) + get(a, n - 3);
}
int main() {
    int t;
    scanf("%d", &t);
    int a[20] = { 1, 1, 2, 4 };
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", get(a, n));
    }
}