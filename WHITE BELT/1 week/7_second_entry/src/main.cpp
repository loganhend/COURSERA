//============================================================================
// Description : Week 1. Second entry of "F" symbol Programming Assignment
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string inputStr;
	cin >> inputStr;
	int cnt = 0;
	for (int i=0; i<inputStr.length(); ++i) {
		if (inputStr[i] == 'f') {
			cnt++;
			if (cnt == 2 ) {
				cout << i << endl;
				break;
			}
		}
	}
	if (cnt == 1) {
		cout << -1 << endl;
	} else if (cnt == 0) {
		cout << -2 << endl;
	}

	return 0;
}
