#include <iostream>
#include <string>
int main() {
	int m, k; std::string s;
	std::cin >> m >> s >> k;
	bool flag = true;
	for (auto c : s) {
		if (c != '0') {
			flag = false;
			break;
		}
	}
	if (flag) {
		std::cout << "YES";
		return 0;
	}
	if (m < k) {
		std::cout << "NO";
		return 0;
	}
	for (int i = 0; i < k; i++) {
		if (s[i + s.size() - k] != '0') {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";
}