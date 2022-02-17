#include <iostream>
#include <vector>
#include <utility>
using namespace std;
long long power(long long a, long long n) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return a;
    auto x = power(a, n / 2);
    return x * x * power(a, n % 2);
}
int main() {
    long long n;
    std::cin >> n;
    long long res = 1;
    for(long long i = 2; i * i <= n; i++) {
        int cnt = 0;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        if(cnt) res *= power(i, cnt - 1) * (i - 1);
    }
    if(n > 1) res *= n - 1;
    std::cout << res;
}