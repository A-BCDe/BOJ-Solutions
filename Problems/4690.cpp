#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int cube(int x) { return x * x * x; }
int main() {
    vector<pair<int, pair<int, pair<int, int>>>> v;
    for(int b = 2; b <= 100; b++) {
        int const bc = cube(b);
        for(int c = b + 1; bc + cube(c) <= 1000000; c++) {
            int const cc = cube(c);
            for(int d = c + 1; bc + cc + cube(d) <= 1000000; d++) {
                int const dc = cube(d);
                int const ac = bc + cc + dc;
                int l = 0, r = ac + 1;
                while(l < r) {
                    long long const m = (l + r) / 2;
                    long long const x = m * m * m;
                    if(x == ac) {
                        v.emplace_back(m, make_pair(b, make_pair(c, d)));
                        break;
                    }
                    if(x < ac) {
                        l = m + 1;
                    }
                    else {
                        r = m;
                    }
                }
            }
        }
    }
    sort(v.begin(), v.end());
    for(auto const &now: v) {
        printf("Cube = %d, Triple = (%d,%d,%d)\n", now.first, now.second.first, now.second.second.first, now.second.second.second);
    }
}