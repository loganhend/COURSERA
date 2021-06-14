//==================================================================================
// Description : Week 2. Programming Assignment. Average temperature
//==================================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> temps(n);
	int sumTemp = 0;
	for (int& t : temps) {
		cin >> t;
		sumTemp += t;
	}
	vector<int> hotDays;
	int avgTemp = sumTemp/n;
	for (int i=0; i<n; ++i) {
		if (temps[i] > avgTemp) {
			hotDays.push_back(i);
		}
	}
	cout << hotDays.size() << endl;
	for (int d : hotDays) {
		cout << d << " ";
	}

}
