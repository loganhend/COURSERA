//==================================================================================
// Description : Week 3. Programming Assignment. Sort vector by abs values
//==================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool getAbsMin(int &x, int &y) {
	return (abs(x)<abs(y));
}

int main() {
	int valuesCnt;
	vector<int> values;
	int val;
	cin >> valuesCnt;
	for (int i=0; i<valuesCnt; ++i) {
		cin >> val;
		values.push_back(val);
	}
	sort(begin(values),end(values),getAbsMin);
	for (const auto& val: values) {
		cout << val << " ";
	}
	cout << endl;
}
