//==================================================================================
// Description : Week 2. Calculate factorial Programming Assignment
//==================================================================================
#include <iostream>
using namespace std;

int Factorial(int num) {
	if (num<=0) {
		return 1;
	}
	if (num==1) {
		return 1;
	} else {
		return num*Factorial(num-1);
	}
}

int main() {
	int num;
	cin >> num;
	cout << Factorial(num) << endl;
}
