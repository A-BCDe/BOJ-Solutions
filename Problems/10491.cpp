#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main() {
    auto str = "problem";
    auto l = strlen(str);

    string s;
    while(getline(cin, s)) {
        bool flag = false;
        for(int i = 0; i <= (int)s.length() - (int)l; i++) {
            flag = true;
            for(int j = 0; j < l; j++) {
                if(s[i + j] != str[j] && s[i + j] != str[j] - 'a' + 'A') { flag = false; break; }
            }
            if(flag) break;
        }
        if(flag) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}