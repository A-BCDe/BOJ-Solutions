#include <string>
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long res = 0;
    long long x = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] > '4') s[i]--;
        res += (s[i] - '0') * x;
        x *= 9;
    }
    cout << res;
}