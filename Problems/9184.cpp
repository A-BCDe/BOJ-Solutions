#include <stdio.h>
int arr[21][21][21];
bool visited[21][21][21];

int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if(visited[a][b][c]) return arr[a][b][c];
    visited[a][b][c] = true;
    if(a < b && b < c) return arr[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    return arr[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) != EOF) {
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}