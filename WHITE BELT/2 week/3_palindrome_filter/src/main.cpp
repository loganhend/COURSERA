//==================================================================================
// Description : Week 2. Find palindromes Programming Assignment
//==================================================================================

#include <iostream>
#include <string>
#include <vector>
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

vector<string> PalindromFilter(vector<string> testStrings, int minLength) {
	vector<string> palindromes;
	for (auto testString : testStrings) {
		if (testString.length()>=minLength) {
			if (IsPalindrom(testString)) {
				palindromes.push_back(testString);
			}
		}
	}
	return palindromes;
}

int main() {
	vector<string> testStr = {"abacaba","aba"}; // @suppress("Invalid arguments")
	int minLength = 5;
	vector<string> test1 = PalindromFilter(testStr, minLength);
	for (auto s : test1) {
		cout << s << ", ";
	}
	cout << endl;
	minLength = 2;
	vector<string> test2 = PalindromFilter(testStr, minLength);
		for (auto s : test2) {
			cout << s << ", ";
		}
		cout << endl;
	minLength = 4;
	testStr = {"weew","bro", "code"};
	vector<string> test3 = PalindromFilter(testStr, minLength);
		for (auto s : test3) {
			cout << s << ", ";
		}
		cout << endl;
	return 0;
}
