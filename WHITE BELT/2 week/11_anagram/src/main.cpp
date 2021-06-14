//==================================================================================
// Description : Week 2. Programming Assignment. Find anagrams
//==================================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,int> BuildCharCounters(const string& inputString) {
	map<char,int> result;
	for (const char& c : inputString) {
		++result[c];
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	string firstWord;
	string secondWord;
	for (int i = 0; i < n; ++i) {
		cin >> firstWord >> secondWord;
		map<char,int> firstMap = BuildCharCounters(firstWord);
		map<char,int> secondMap = BuildCharCounters(secondWord);
		if (firstMap == secondMap) {
			cout << "YES" << endl;
		} else {
			cout << "NO" <<endl;
		}
	}

	return 0;
}
