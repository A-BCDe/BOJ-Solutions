#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll to_hex(string const& s) {
	ll res = 0;
	for (int i = 2; i < s.size(); i++) {
		res *= 16;
		if (s[i] >= '0' && s[i] <= '9') {
			res += s[i] - '0';
		}
		else {
			res += s[i] - 'a' + 10;
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(6);
	string s, t;
	vector<ull> v;
	vector<vector<ull>> primes = {
		{},
		{},
		{},
		{2},
		{3},
		{5},
		{2},
		{13},
		{3,7},
		{2,17},
		{5,11},
		{89},
		{2,3},
		{233},
		{13, 29},
		{2, 5, 61},
		{3,7,47},
		{1597},
		{2,17,19},
		{37,113},
		{3,5,11,41},
		{2,13,421},
		{89,199},
		{28657},
		{2,3,7,23},
		{5,3001},
		{233,521},
		{2,17,53,109},
		{3,13,29,281},
		{514229},
		{2,5,11,31,61},
		{557,2417},
		{3,7,47,2207},
		{2,89,19801},
		{1597,3571},
		{5,13,141961},
		{2,3,17,19,107},
		{73,149,2221},
		{37, 113,9349},
		{2,233,135721},
		{3,5,7,11,41,2161},
		{2789,59369},
		{2,13,29,211,421},
		{433494437},
		{3,43,89,199,307},
		{2,5,17,61,109441},
		{139,461,28657},
		{2971215073},
		{2,3,7,23,47,1103},
		{13,97,6168709},
		{5,11,101,151,3001},
		{2,1597,6376021},
		{3,233,521,90481},
		{953,55945741},
		{2,17,19,53,109,5779},
		{5,89,661,474541},
		{3,7,13,29,281,14503},
		{2,37,113,797,54833},
		{59,19489,514229},
		{353,2710260697},
		{2,3,5,11,31,41,61,2521},
		{4513,555003497},
		{557,2417,3010349},
		{2,13,17,421,35239681},
		{3,7,47,1087,2207,4481},
		{5,233,14736206161},
		{2,89,199,9901,19801},
		{269,116849,1429913},
		{3,67,1597,3571,63443},
		{2,137,829,18077,28657},
		{5,11,13,29,71,911,141961},
		{6673,46165371073},
		{2,3,7,17,19,23,107,103681},
		{9375829,86020717},
		{73,149,2221,54018521},
		{2,5,61,3001,230686501},
		{3,37,113,9349,29134601},
		{13,89,988681,4832521},
		{2,79,233,521,859,135721},
		{157,92180471494753},
		{3,5,7,11,41,47,1601,2161,3041},
		{2,17,53,109,2269,4373,19441},
		{2789,59369,370248451},
		{99194853094755497},
		{2,3,13,29,83,211,281,421,1427},
		{5,1597,9521,3415914041},
		{6709,144481,433494437},
		{2,173,514229,3821263937},
		{3,7,43,89,199,263,307,881,967},
		{1069,1665088321800481},
		{2,5,11,17,19,31,61,181, 541, 109441},
		{13,233,741469,159607993},
		{3,139,461,4969,28657,275449},
		{2,557,2417,4531100550901}
	};
	vector<ull> prime;
	ull a = 1, b = 0;
	while (a < 0x8000000000000000) {
		v.push_back(b);
		auto tmp = b;
		b = a;
		a += tmp;
	}
	while (true) {
		cin >> s >> t;
		if (cin.eof()) break;
		ull a = to_hex(s), b = to_hex(t);
		if (a >= b) break;
		cout << "Range " << a << " to " << b << ":\n";
		auto lower = lower_bound(v.begin(), v.end(), a);
		auto higher = upper_bound(v.begin(), v.end(), b);
		if (lower == higher) {
			cout << "No Fibonacci numbers in the range\n\n";
			continue;
		}
		for (auto it = lower; it != higher; it++) {
			cout << "Fib(" << it - v.begin() << ") = " << *it << ", lg";
			if (*it == 0) {
				cout << " does not exist\n";
				continue;
			}
			cout << " is " << log2((long double)*it) << '\n';
			if (*it == 0 || *it == 1) {
				cout << "No prime factors\n";
			}
			else {
				cout << "Prime factors:";
				auto cur = *it;
				for (auto now : primes[it - v.begin()]) {
					while (cur % now == 0) {
						cout << ' ' << now;
						cur /= now;
					}
				}
				cout << '\n';
			}
		}
		cout << '\n';
	}
}