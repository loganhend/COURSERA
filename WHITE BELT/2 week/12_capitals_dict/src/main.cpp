//==================================================================================
// Description : Week 2. Programming Assignment. Countries dictionary
//==================================================================================

/*
* 6
* CHANGE_CAPITAL RussianEmpire Petrograd
* RENAME RussianEmpire RussianRepublic
* ABOUT RussianRepublic
* RENAME RussianRepublic USSR
* CHANGE_CAPITAL USSR Moscow
* DUMP
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

bool checkKey(const map<string,string>& inputMap, const string& key) {
	for (const auto& i: inputMap) {
		if (i.first == key) {
			return true;
		}
	}
	return false;
}


int main() {
	int q;
	cin >> q;
	string op;
	string param1;
	string param2;
	map<string, string> countries;

	for (int i=0; i<q; ++i) {
		cin >> op;
		if (op == "CHANGE_CAPITAL") {
			cin >> param1 >> param2;
			bool hasKey = checkKey(countries,param1);
			if (!hasKey) {
				cout << "Introduce new country " << param1 << " with capital " << param2 << endl;
			} else {
				if (countries[param1] == param2) {
					cout << "Country " << param1 <<" hasn't changed its capital" << endl;
				} else {
					cout << "Country "<< param1 <<" has changed its capital from " <<
							countries[param1] << " to " << param2 << endl;
				}
			}
			countries[param1] = param2;
		}
		if (op == "RENAME") {
			cin >> param1 >> param2;
			if (param1 == param2 || !checkKey(countries, param1) || checkKey(countries, param2)) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				string capital = countries[param1];
				countries.erase(param1);
				countries[param2] = capital;
				cout << "Country " << param1 << " with capital " << capital <<
						" has been renamed to " << param2 << endl;
			}
		}
		if (op == "ABOUT") {
			cin >> param1;
			if (!checkKey(countries,param1)) {
				cout << "Country "<< param1 <<" doesn't exist" << endl;
			} else {
				cout << "Country "<< param1 <<" has capital " << countries[param1] << endl;
			}
		}
		if (op == "DUMP") {
			if (countries.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				for (const auto& country: countries) {
					cout << country.first << "/" << country.second << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
