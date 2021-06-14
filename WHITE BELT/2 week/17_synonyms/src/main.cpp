//==================================================================================
// Description : Week 2. Programming Assignment. Synonyms
//==================================================================================

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
	int queries;
	cin >> queries;
	string op,word1, word2;
	map< string,set<string> > synonyms;
	for (int i=0; i<queries; ++i) {
		cin >> op;
		if (op=="ADD") {
			cin >> word1 >> word2;
			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
			continue;
		}
		if (op=="COUNT") {
			cin >> word1;
			cout << synonyms[word1].size() << endl;
			continue;
		}
		if (op=="CHECK") {
			cin >> word1 >> word2;
			int isSynonym = synonyms[word1].count(word2);
			if (isSynonym==0) {
				cout << "NO" <<endl;
			} else {
				cout << "YES" <<endl;
			}
		}
	}
	return 0;
}
