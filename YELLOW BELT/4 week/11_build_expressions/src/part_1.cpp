#include <string>
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;


int main() {
	deque<string> s;
	int start_, n;
	cin >> start_ >> n;
	s.push_back(to_string(start_));
	string op, val;
	for (int i=1; i <= n; i++) {
		cin >> op >> val;
		s.push_front("(");
		s.push_back(")");
		s.push_back(" " + op + " " + val);
	}
	stringstream ss;
	for (auto s_ : s) {
		ss << s_;
	}
	cout << ss.str() << endl;

}
