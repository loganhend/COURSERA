//==================================================================================
// Description : Week 1. Convert decimal to binary Programming Assignment
//==================================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int decimalNum;
	cin >> decimalNum;
	vector<int> binVector;
	do {
		binVector.push_back(decimalNum % 2);
		decimalNum /= 2;
	} while (decimalNum > 1);
	if (decimalNum == 1) {
		cout << decimalNum;
	}
	for (int i=(binVector.size()-1); i>=0; i--) {
		cout << binVector[i];
	}
	return 0;
}
