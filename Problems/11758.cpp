#include <iostream>
int main() {
    int a,b,c,d,e,f;
    std::cin>>a>>b>>c>>d>>e>>f;
    int x1 = c - a;
    int y1 = d - b;
    int x2 = e - c;
    int y2 = f - d;
    // (2, 4), (1, 5)
    // x1 y2 - x2 y1
    int res = x1 * y2 - x2 * y1;
    if(res > 0) std::cout << "1";
    else if(res < 0) std::cout << "-1";
    else std::cout << "0";
}