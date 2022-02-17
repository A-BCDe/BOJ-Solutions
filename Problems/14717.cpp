#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int rank;
    if(a == b) {
        rank = 9 + a;
    }
    else {
        rank = (a + b) % 10;
    }
    int cnt = 0;
    int win = 0;
    for(int i = 2; i <= 21; i++) {
        if(a << 1 == i || 1 + (b << 1) == i) continue;
        for(int j = i + 1; j <= 21; j++) {
            if(a << 1 == j || 1 + (b << 1) == j) continue;
            int r;
            if(i / 2 == j / 2) {
                r = 9 + i / 2;
            }
            else {
                r = (i / 2 + j / 2) % 10;
            }
            if(rank > r) win++;
            cnt++;
        }
    }
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << (double)win / (double)(cnt);
}