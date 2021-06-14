//==================================================================================
// Description : Week 2. Sort two numbers with swap Programming Assignment
//==================================================================================


#include <iostream>
using namespace std;

void UpdateIfGreater(int a, int& b) {
	if (a>b) {
		b = a;
	}
}

int main() {
	int a = 4;
	int b = 2;
	UpdateIfGreater(a,b);
	cout << a << endl;
	cout << b << endl;
	return 0;
}
