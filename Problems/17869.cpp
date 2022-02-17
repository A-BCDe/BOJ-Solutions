#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    int cnt = 0;
    while(n != 1) {
        if(n % 2) {
            n++;
        }
        else {
            n >>= 1;
        }
        cnt++;
    }
    cout << cnt;
}