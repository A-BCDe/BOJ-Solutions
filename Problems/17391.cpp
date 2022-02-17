#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    auto a = new int*[n];
    auto visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            visited[i][j] = false;
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));

    while(!q.empty()) {
        auto const now = q.front();
        q.pop();
        if(visited[now.first.first][now.first.second]) continue;
        visited[now.first.first][now.first.second] = true;
        if(now.first.first == n - 1 && now.first.second == m - 1) {
            printf("%d", now.second);
            break;
        }
        for(int i = 1; i <= a[now.first.first][now.first.second]; i++) {
            if(now.first.first + i < n && !visited[now.first.first + i][now.first.second])
                q.push(make_pair(make_pair(now.first.first + i, now.first.second), now.second + 1));
            if(now.first.second + i < m && !visited[now.first.first][now.first.second + i])
                q.push(make_pair(make_pair(now.first.first, now.first.second + i), now.second + 1));
        }
    }

    for(int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] visited[i];
    }
    delete[] a;
    delete[] visited;
}
