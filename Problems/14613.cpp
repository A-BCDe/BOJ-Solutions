// 1500 : W - L = -10
// 2000 : W - L = 0
// 2500 : W - L = 10
// 3000 : W - L = 20
#include <iostream>
using namespace std;
double pow(double a, int n) {
    if(n == 0) return 1;
    if(n == 1) return a;
    double x = pow(a, n / 2);
    return x * x * pow(a, n % 2);
}
long long fun(int w, int l) {
    long long res = 1;
    int x;
    for(x = 1; x <= w; x++) {
        res *= 21 - x;
        res /= x;
    }
    for(; x <= w + l; x++) {
        res *= 21 - x;
        res /= (x - w);
    }
    for(; x <= 20; x++) {
        res *= 21 - x;
        res /= (x - w - l);
    }
    return res;
}
int main() {
    double W, L, D;
    cin >> W >> L >> D;
    double b = 0, s = 0, g = 0, p = 0, d = 0;
    for(int w = 0; w <= 20; w++) {
        for(int l = 0; l + w <= 20; l++) {
            int x = w - l;
            double y = pow(W, w) * pow(L, l) * pow(D, 20 - w - l);
            y *= fun(w, l);
            if(x < -10) b += y;
            else if(x < 0) s += y;
            else if(x < 10) g += y;
            else if(x < 20) p += y;
            else d += y;
        }
    }
    cout << fixed;
    cout.precision(8);
    cout << b << endl;
    cout << s << endl;
    cout << g << endl;
    cout << p << endl;
    cout << d << endl;
}