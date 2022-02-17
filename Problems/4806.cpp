#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int n = 0;
    while(getline(cin, s)) {
        n++;
    }
    cout << n;
}