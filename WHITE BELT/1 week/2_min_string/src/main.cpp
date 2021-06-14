//============================================================================
// Name        : w_1_pa_1_a_b.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Week 1. Minimal string Programming Assignment
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1,str2,str3;
	cin >> str1 >> str2 >> str3;
	string minString;
	if (str1<=str2) {
		if (str1<=str3) {
			minString = str1;
		} else {
			minString = str3;
		}
	} else {
		if (str2 <= str3) {
			minString = str2;
		} else {
			minString = str3;
		}
	}
	cout << minString;
	return 0;
}


