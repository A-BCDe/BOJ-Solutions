#include <stdio.h>
int f(char const* const* a, bool* const* visited, bool* character, int const r, int const c, int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c || visited[x][y] || character[a[x][y] - 'A']) return 0;
	visited[x][y] = true;
	character[a[x][y] - 'A'] = true;
	int res = 0;
	int t1 = f(a, visited, character, r, c, x - 1, y);
	int t2 = f(a, visited, character, r, c, x, y - 1);
	int t3 = f(a, visited, character, r, c, x + 1, y);
	int t4 = f(a, visited, character, r, c, x, y + 1);
	res = t1;
	if (res < t2) res = t2;
	if (res < t3) res = t3;
	if (res < t4) res = t4;
	visited[x][y] = false;
	character[a[x][y] - 'A'] = false;
	return res + 1;
}
int main() {
	int r, c;
	scanf("%d%d", &r, &c);
	auto a = new char* [r];
	auto visited = new bool* [r];
	bool character[26] = {};
	for (int i = 0; i < r; i++) {
		a[i] = new char[c + 1];
		visited[i] = new bool[c]();
		scanf("%s", a[i]);
	}
	printf("%d", f(a, visited, character, r, c, 0, 0));
	for (int i = 0; i < r; i++) {
		delete[] a[i];
	}
	delete[] a;
}