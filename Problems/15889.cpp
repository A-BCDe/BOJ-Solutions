#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    auto visited = new bool[n]();
    visited[0] = true;


    auto a = new int[n];
    scanf("%d", &a[0]);
    for(int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        if(!visited[i]) {
            printf("A");
            return 0;
        }
        int x;
        scanf("%d", &x);
        for(int j = i + 1; j < n && a[j] - a[i] <= x; j++) {
            visited[j] = true;
        }
        if(visited[n - 1]) {
            printf("B");
            return 0;
        }
    }
    printf(n == 1 ? "B" : "A");

    delete[] visited;
    delete[] a;
}