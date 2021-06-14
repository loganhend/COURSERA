//==================================================================================
// Description : Week 2. Programming Assignment. Count unique strings
//==================================================================================

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int stringsCount;
	set<string> uniqueWords;
	string word;
	cin >> stringsCount;
	for (int i=0; i<stringsCount; ++i) {
		cin >> word;
		uniqueWords.insert(word);
	}
	cout << uniqueWords.size() << endl;
	return 0;
}
