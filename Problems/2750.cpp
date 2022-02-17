#include <stdio.h>
#include <algorithm>
int main() {
    int n;
    scanf("%d", &n);
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    delete[] a;
}