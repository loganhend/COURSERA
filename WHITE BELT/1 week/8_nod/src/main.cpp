//==================================================================================
// Description : Week 1. Smallest common denominator symbol Programming Assignment
//==================================================================================

#include <iostream>
using namespace std;

int main() {
	int n1,n2;
	cin >> n1 >> n2;
	int minNum;
	while (n1 > 0 && n2 >0) {
		if (n1 > n2) {
			n1 = n1 % n2;
		} else {
			n2 = n2 % n1;
		}
	}
	cout << (n1+n2);
	return 0;
}
