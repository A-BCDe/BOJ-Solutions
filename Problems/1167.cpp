#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    auto v = new vector<pair<int, int>>[n + 1];
    for(int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        int x, y;
    A:
        scanf("%d", &x);
        if(x == -1) continue;
        scanf("%d", &y);
        v[cur].emplace_back(x, y);
        goto A;
    }
    auto visited = new bool[n + 1]();
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    int max = 0;
    int maxi = 1;
    while(!q.empty()) {
        auto const now = q.front();
        q.pop();
        visited[now.first] = true;
        bool flag = true;
        for(auto const next : v[now.first]) {
            // now.second : root에서부터 now.first까지의 거리
            if(visited[next.first]) continue;
            flag = false;
            q.push(make_pair(next.first, now.second + next.second));
        }
        if(flag) {
            if (max < now.second) {
                max = now.second;
                maxi = now.first;
            }
        }
    }
    delete[] visited;
    visited = new bool[n + 1]();
    q.push(make_pair(maxi, 0));
    while (!q.empty()) {
        auto const now = q.front();
        q.pop();
        visited[now.first] = true;
        bool flag = true;
        for (auto const next : v[now.first]) {
            if (visited[next.first]) continue;
            flag = false;
            q.push(make_pair(next.first, now.second + next.second));
        }
        if (flag) {
            if (max < now.second) {
                max = now.second;
                maxi = now.first;
            }
        }
    }
    printf("%d", max);
    delete[] visited;
}