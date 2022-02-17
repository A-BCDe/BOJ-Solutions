#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	while (true) {
		int x;
		scanf("%d", &x);
		if (x == 0) return 0;
		vector<int> v;
		while (x) {
			v.push_back(x % 2);
			x /= 2;
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			
		}
	}
}