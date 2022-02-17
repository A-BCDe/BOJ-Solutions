#include <cstdio>
#include <array>
#include <queue>
#include <utility>
using namespace std;
void find_rbo(array<array<char, 10>, 10> const& board, int n, int m, pair<int, int>& r, pair<int, int>& b, pair<int, int>& o) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
		if (board[i][j] == 'R') { r = make_pair(i, j); cnt++; }
		else if (board[i][j] == 'B') { b = make_pair(i, j); cnt++; }
		else if (board[i][j] == 'O') { o = make_pair(i, j); cnt++; }
		if (cnt == 3) break;
	}
}
void clear_board(array<array<char, 10>, 10>& board, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R' || board[i][j] == 'B' || board[i][j] == 'O') board[i][j] = '.';
		}
	}
}
array<array<char, 10>, 10> insert_rbo(array<array<char, 10>, 10> const& board, int n, int m, pair<int, int> r, pair<int, int> b, pair<int, int> o) {
	array<array<char, 10>, 10> bd = board;
	clear_board(bd, n, m);
	bd[r.first][r.second] = 'R';
	bd[b.first][b.second] = 'B';
	bd[o.first][o.second] = 'O';
	return bd;
}
int main() {
	int n, m;
	scanf("%d%d\n", &n, &m);
	array<array<char, 10>, 10> board;
	for (int i = 0; i < n; i++) {
		char buf[11];
		scanf("%s", buf);
		for (int j = 0; j < m; j++) {
			board[i][j] = buf[j];
		}
	}
	queue<pair<int, array<array<char, 10>, 10>>> q;
	q.push(make_pair(0, std::move(board)));
	while (true) {
		if (q.empty()) break;
		auto const now = std::move(q.front()); q.pop();
		if (now.first != 10) {
			pair<int, int> r, b, o;
			find_rbo(now.second, n, m, r, b, o);
			// right
			if (r.second < b.second) {
				auto bd = now.second;
				while (b.second < m - 1 && bd[b.first][b.second + 1] != '#') {
					if (now.second[b.first][b.second + 1] == 'O') goto LEFT;
					bd[b.first][b.second] = '.';
					bd[b.first][++b.second] = 'B';
				}
				while (r.second < m - 1 && now.second[r.first][r.second + 1] != '#' && now.second[r.first][r.second + 1] != 'B') {
					if (now.second[r.first][r.second + 1] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[r.first][++r.second] = 'R';
				}
				q.push(make_pair(now.first + 1, bd));
			}
			else {
				auto bd = now.second;
				while (r.second < m - 1 && now.second[r.first][r.second + 1] != '#') {
					if (now.second[r.first][r.second + 1] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[r.first][++r.second] = 'R';
				}
				while (b.second < m - 1 && now.second[b.first][b.second + 1] != '#' && now.second[b.first][b.second + 1] != 'R') {
					if (now.second[b.first][b.second + 1] == 'O') goto LEFT;
					bd[b.first][b.second] = '.';
					bd[b.first][++b.second] = 'B';
				}
				q.push(make_pair(now.first + 1, bd));
			}
		LEFT:
			// left
			if (r.second < b.second) {
				auto bd = now.second;
				while (r.second > 0 && now.second[r.first][r.second - 1] != '#') {
					if (now.second[r.first][r.second - 1] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[r.first][--r.second] = 'R';
				}
				while (b.second > 0 && now.second[b.first][b.second - 1] != '#' && now.second[b.first][b.second - 1] != 'R') {
					if (now.second[b.first][b.second + 1] == 'O') goto UP;
					bd[b.first][b.second] = '.';
					bd[b.first][--b.second] = 'B';
				}
				q.push(make_pair(now.first + 1, bd));
			}
			else {
				auto bd = now.second;
				while (b.second > 0 && now.second[b.first][b.second - 1] != '#') {
					if (now.second[b.first][b.second - 1] == 'O') goto UP;
					bd[b.first][b.second] = '.';
					bd[b.first][--b.second] = 'B';
				}
				while (r.second > 0 && now.second[r.first][r.second - 1] != '#' && now.second[r.first][r.second - 1] != 'B') {
					if (now.second[r.first][r.second - 1] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[r.first][--r.second] = 'R';
				}
				q.push(make_pair(now.first + 1, insert_rbo(now.second, n, m, r, b, o)));
			}
		UP:
			// up
			if (r.first < b.first) {
				auto bd = now.second;
				while (r.first > 0 && now.second[r.first - 1][r.second] != '#') {
					if (now.second[r.first - 1][r.second] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[--r.first][r.second] = 'R';
				}
				while (b.first > 0 && now.second[b.first - 1][b.second] != '#' && now.second[b.first - 1][b.second] != 'R') {
					if (now.second[b.first - 1][b.second] == 'O') goto DOWN;
					bd[b.first][b.second] = '.';
					bd[--b.first][b.second] = 'B';
				}
				q.push(make_pair(now.first + 1, bd));
			}
			else {
				auto bd = now.second;
				while (b.first > 0 && now.second[b.first - 1][b.second] != '#') {
					if (now.second[b.first - 1][b.second] == 'O') goto DOWN;
					bd[b.first][b.second] = '.';
					bd[--b.first][b.second] = 'B';
				}
				while (r.first > 0 && now.second[r.first - 1][r.second] != '#' && now.second[r.first - 1][r.second] != 'B') {
					if (now.second[r.first - 1][r.second] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[--r.first][r.second] = 'R';
				}
				q.push(make_pair(now.first + 1, insert_rbo(now.second, n, m, r, b, o)));
			}
		DOWN:
			// down
			if (r.first > b.first) {
				auto bd = now.second;
				while (r.first < n - 1 && now.second[r.first + 1][r.second] != '#') {
					if (now.second[r.first + 1][r.second] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[++r.first][r.second] = 'R';
				}
				while (b.first < n - 1 && now.second[b.first + 1][b.second] != '#' && now.second[b.first + 1][b.second] != 'R') {
					if (now.second[b.first + 1][b.second] == 'O') goto END;
					bd[b.first][b.second] = '.';
					bd[++b.first][b.second] = 'B';
				}
				q.push(make_pair(now.first + 1, bd));
			}
			else {
				auto bd = now.second;
				while (b.first < n - 1 && now.second[b.first + 1][b.second] != '#') {
					if (now.second[b.first + 1][b.second] == 'O') goto END;
					bd[b.first][b.second] = '.';
					bd[++b.first][b.second] = 'B';
				}
				while (r.first < n - 1 && now.second[r.first + 1][r.second] != '#' && now.second[r.first + 1][r.second] != 'B') {
					if (now.second[r.first + 1][r.second] == 'O') {
						printf("%d", now.first + 1);
						return 0;
					}
					bd[r.first][r.second] = '.';
					bd[++r.first][r.second] = 'R';
				}
				q.push(make_pair(now.first + 1, bd));
			}
		END:
			printf("");
		}
	}
	printf("-1");
}