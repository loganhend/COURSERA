#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {
private:
	vector<int> yearsChangeFirstName;
	vector<int> yearsChangeLastName;
	map<int,string> FirstNames;
	map<int,string> LastNames;
	int findChangeYear(int year, vector<int> intSet) {
		int resultYear = -1;
		for (int c=0; c < intSet.size(); ++c) {
			if (year >= intSet[c]) {
				resultYear = intSet[c];
			} else {
				break;
			}
		}
		return resultYear;
	}
public:
	void ChangeFirstName(int year, const string& first_name){
		yearsChangeFirstName.push_back(year);
		sort(begin(yearsChangeFirstName),end(yearsChangeFirstName));
		FirstNames[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name){
		yearsChangeLastName.push_back(year);
		sort(begin(yearsChangeLastName),end(yearsChangeLastName));
		LastNames[year] = last_name;
	}
	string GetFullName(int year){
		string firstName,lastName;
		int actualChangeFirstName,actualChangeLastName;
		actualChangeFirstName = findChangeYear(year,yearsChangeFirstName);
		actualChangeLastName = findChangeYear(year,yearsChangeLastName);
		if (actualChangeFirstName == -1) {
			if (actualChangeLastName == -1) {
				return "Incognito";
			} else {
				lastName = LastNames[actualChangeLastName];
				return lastName + " with unknown first name";
			}
		} else {
			if (actualChangeLastName == -1) {
				firstName = FirstNames[actualChangeFirstName];
				return firstName + " with unknown last name";
			} else {
				firstName = FirstNames[actualChangeFirstName];
				lastName = LastNames[actualChangeLastName];
				return firstName + " " + lastName;
			}
		}

	}
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
