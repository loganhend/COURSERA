//==================================================================================
// Description : Week 3. Programming Assignment. Not case sensitive sort
//==================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int main() {
	int valuesCnt;
	vector<string> values;
	string val;
	cin >> valuesCnt;
	for (int i=0; i<valuesCnt; ++i) {
		cin >> val;
		values.push_back(val);
	}
	sort(begin(values),end(values),[](string x, string y){
		for (auto& c: x){
			c = tolower(c);
		}
		for (auto& c: y){
			c = tolower(c);
		}
		return (x<y);

	});
	for (const auto& val: values) {
			cout << val << " ";
	}
	return 0;
}
