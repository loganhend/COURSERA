#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string GetString(int n) {
	stringstream ss;
	for (int i = n; i>0; i--) {
		ss << i;
	}
	return ss.str();
}

ostream& operator << (ostream& out, const string& str) {
	bool first = true;
	for (const auto& s: str) {
		if (!first) {
			out << " ";
		}
		out << s ;
		first = false;
	}
	return out;
}

void GetPermutations(string s) {
	sort(begin(s),end(s));
	reverse(begin(s),end(s));
	do {
		cout << s << endl;
	} while (prev_permutation(begin(s),end(s)));
}

int main() {
	int n;
	cin >> n;
	GetPermutations(GetString(n));
	return 0;
}
