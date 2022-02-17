#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
    int c, r, n = 0;
    vector<pair<int, int>> v;
    pair<int, int> park[100] = {};
    scanf("%d%d", &c, &r);
    auto a = new char*[c];
    for(int i = 0; i < c; i++) {
        a[i] = new char[r + 1];
        scanf("%s", a[i]);
        for(int j = 0; j < r; j++) {
            if(a[i][j] == 'C') {
                v.emplace_back(i, j);
            }
            else if(a[i][j] == 'P') {
                park[n].first = i;
                park[n].second = j;
                n++;
            }
        }
    }

    sort(park, park + n);

    vector<pair<int, pair<int, int>>> dist;

    int cnt = 0;

    int car = 0;

    for(auto const &item: v) {
        queue<pair<pair<int, int>, int>> q;
        auto visited = new bool*[c];
        for(int i = 0; i < c; i++) {
            visited[i] = new bool[r]();
        }

        q.push(make_pair(item, 0));
        int incnt = 0;
        while(!q.empty() && incnt < n) {
            auto const now = q.front();
            q.pop();
            if(visited[now.first.first][now.first.second]) continue;
            visited[now.first.first][now.first.second] = true;

            if(a[now.first.first][now.first.second] == 'P') {
                auto ptr = lower_bound(park, park + n, make_pair(now.first.first, now.first.second));
                //printf("%p\n", ptr);
                int x = ptr - park;
                //printf("x = %d\n", x);
                dist.emplace_back(now.second, make_pair(car, x));
                incnt++;
                cnt++;
            }

            if(now.first.first > 0 && a[now.first.first - 1][now.first.second] != 'X' && !visited[now.first.first - 1][now.first.second]) {
                q.push(make_pair(make_pair(now.first.first - 1, now.first.second), now.second + 1));
            }
            if(now.first.second > 0 && a[now.first.first][now.first.second - 1] != 'X' && !visited[now.first.first][now.first.second - 1]) {
                q.push(make_pair(make_pair(now.first.first, now.first.second - 1), now.second + 1));
            }
            if(now.first.first < c - 1 && a[now.first.first + 1][now.first.second] != 'X' && !visited[now.first.first + 1][now.first.second]) {
                q.push(make_pair(make_pair(now.first.first + 1, now.first.second), now.second + 1));
            }
            if(now.first.second < r - 1 && a[now.first.first][now.first.second + 1] != 'X' && !visited[now.first.first][now.first.second + 1]) {
                q.push(make_pair(make_pair(now.first.first, now.first.second + 1), now.second + 1));
            }
        }

        for(int i = 0; i < c; i++) {
            delete[] visited[i];
        }
        delete[] visited;
        car++;
    }

    bool flag = false;
    int ans = -1;

    sort(dist.begin(), dist.end());

    int l = dist.front().first;
    r = dist.back().first + 1;

    while(l < r) {
        int const m = (l + r) / 2;
        auto const end = lower_bound(dist.begin(), dist.end(), make_pair(m + 1, make_pair(0, 0)));
        auto cc = new bool[n]();
        auto pp = new bool[n]();
        auto vv = new vector<int>[n]();

        for(auto it = dist.begin(); it != end; it++) {
            vv[it->second.first].push_back(it->second.second);
        }
        for(int i = 0; i < n; i++) {
            for(auto now: vv[i]) {
                if(!pp[now]) {

                }
            }
        }

        delete[] vv;
        delete[] cc;
        delete[] pp;
    }

    for(int i = 0; i < c; i++) {
        delete[] a[i];
    }
    delete[] a;
}