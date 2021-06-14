//============================================================================
// Description : Week 1. Division Programming Assignment
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n1,n2;
	cin >> n1 >> n2;
	if (n2 == 0) {
		cout << "Impossible";
	} else {
		cout << n1/n2;
	}

	return 0;
}
