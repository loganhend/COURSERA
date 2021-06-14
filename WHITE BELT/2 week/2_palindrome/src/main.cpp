//==================================================================================
// Description : Week 2. Test that word is palindrome Programming Assignment
//==================================================================================

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string testString) {
	if (testString=="") {
		return true;
	}
	int strLength = testString.length();
	for (int i=0; i<=(strLength/2); ++i) {
		if (testString[i]!=testString[strLength-1-i]) {
			return false;
		}
	}
	return true;
}

int main() {
	string inputString;
	cin >> inputString;
	cout << IsPalindrom(inputString);
	return 0;
}
