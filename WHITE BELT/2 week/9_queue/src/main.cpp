//==================================================================================
// Description : Week 2. Programming Assignment. Queue modeling
//==================================================================================


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	string op;
	int num;
	vector<int> queue;
	vector<int> counts;
	for (int i=1; i<=n; ++i) {
		cin >> op;
		if (op == "WORRY") {
			cin >> num;
			queue[num] = 1;
			continue;
		}
		if (op == "QUIET") {
			cin >> num;
			queue[num] = 0;
			continue;
		}
		if (op == "COME") {
			cin >> num;
			queue.resize(queue.size()+num);
			continue;
		}
		if (op == "WORRY_COUNT") {
			//counts.push_back(WorryCount(queue));
			int w = count(begin(queue), end(queue), 1);
			counts.push_back(w);
		}
	}
	for (int c : counts) {
		cout << c << endl;
	}
}
