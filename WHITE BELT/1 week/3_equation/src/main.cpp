//============================================================================
// Name        : w_1_pa_1_a_b.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Week 1. Minimal string Programming Assignment
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float a,b,c;
	double x1,x2;
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			cout << " ";
		} else {
			x1 = -c/b;
			cout << x1;
		}
	} else {
		if (c == 0) {
			x1 = 0;
			x2 = -b/a;
			cout << x1 << " " << x2;
		} else {
			double det = pow(b,2) - 4*a*c;
				if (det<0) {
					cout << " ";
				} else {
					x1 = (-b + sqrt(det)) / (2*a);
					x2 = (-b - sqrt(det)) / (2*a);
					if (x1==x2) {
						cout << x1;
					} else {
						cout << x1 << " " << x2;
					}
				}
		}
	}
	return 0;
}
