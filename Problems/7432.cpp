#include <iostream>
#include <set>
#include <string>
using namespace std;
struct directory {
	set<directory*> children;
	string name;
	directory(string name) : children(), name(move(name)) {}
};
int parse(string const &input, directory* root, int idx) {
	int const start = idx;
	while (idx < input.size()) {
		if (input[idx] == '\\') break;
	}
	int const end = idx;
	string next = input.substr(start, end - start);
	
	return idx + 1;
}
int main() {

}