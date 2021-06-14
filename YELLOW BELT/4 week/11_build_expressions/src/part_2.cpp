#include <string>
#include <deque>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {
	deque<string> s;
	map<string,int> ops;
	ops["+"]= 0;
	ops["-"]= 0;
	ops["/"]= 1;
	ops["*"]= 1;

	int start_, n;
	cin >> start_ >> n;
	s.push_back(to_string(start_));
	string op, val, prev_op;
	prev_op = "/";
	for (int i=1; i <= n; i++) {
		cin >> op >> val;
		if (ops[op]>ops[prev_op]){
			s.push_front("(");
			s.push_back(")");
		}
		s.push_back(" " + op + " " + val);
		prev_op = op;
	}
	stringstream ss;
	for (auto s_ : s) {
		ss << s_;
	}
	cout << ss.str() << endl;

}
