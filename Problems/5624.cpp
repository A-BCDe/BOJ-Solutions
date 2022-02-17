#include <stdio.h>
#include <set>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	set<int> s;
	auto a = new int[n];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++) {
			auto it = s.find(a[i] - a[j]);
			if (it != s.end()) {
				cnt++;
				break;
			}
		}
		for (int j = 0; j <= i; j++) {
			if (s.find(a[i] + a[j]) == s.end()) {
				s.insert(a[i] + a[j]);
			}
		}
	}
	printf("%d", cnt);
}