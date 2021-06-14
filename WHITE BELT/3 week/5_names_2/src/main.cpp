#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
	map<int,string> FirstNames;
	map<int,string> LastNames;
	string findChangeByYear(int year, const map<int,string>& namesSet) {
		string foundName;
		for (auto item: namesSet) {
			if (year >= item.first) {
				foundName = item.second;
			} else {
				break;
			}
		}
		return foundName;
	}
	vector<string> inverseVector(const vector<string>& inputVector) {
		vector<string> inversed;
		for (int k=inputVector.size()-1; k>=0;--k) {
			inversed.push_back(inputVector[k]);
		}
		return inversed;
	}
	vector<string> findChangeHistory(int year, map<int,string> namesSet, string currentName) {
		vector<string> foundNames;
		string prevChange = "";
		for (auto item: namesSet) {
			if (year > item.first) {
				if (item.second != prevChange) {
					foundNames.push_back(item.second);
				}
			} else {
				break;
			}
			prevChange = item.second;
		}
		foundNames = inverseVector(foundNames);
		if (foundNames.size()>0) {
			if (foundNames[0]==currentName) {
				foundNames.erase(foundNames.begin());
			}
		}
		return foundNames;
	}
public:
	void ChangeFirstName(int year, const string& first_name){
		FirstNames[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name){
		LastNames[year] = last_name;
	}
	string GetFullName(int year){
		string firstName,lastName;
		firstName = findChangeByYear(year,FirstNames);
		lastName = findChangeByYear(year,LastNames);
		if (firstName.empty()) {
			if (lastName.empty()) {
				return "Incognito";
			} else {
				return lastName + " with unknown first name";
			}
		} else {
			if (lastName.empty()) {
				return firstName + " with unknown last name";
			} else {
				return firstName + " " + lastName;
			}
		}

	}
	string GetFullNameWithHistory(int year) {
		string firstName,lastName;
		string fullFirstName,fullLastName;
		firstName = findChangeByYear(year,FirstNames);
		lastName = findChangeByYear(year,LastNames);
		vector<string> FirstNameHistory = findChangeHistory(year,FirstNames, firstName);
		vector<string> LastNameHistory = findChangeHistory(year,LastNames, lastName);
		int c = 0;
		if (FirstNameHistory.size()>0) {
			firstName += " (";
			for (auto fName: FirstNameHistory) {
				if (c>0) {
					firstName += (", " + fName);
				} else {
					firstName += (fName);
				}
				c++;
			}
			firstName += ")";
		}
		c = 0;
		if (LastNameHistory.size()>0) {
			lastName += " (";
			for (auto lName: LastNameHistory) {
				if (c>0) {
					lastName += (", " + lName);
				} else {
					lastName += (lName);
				}
				c++;
			}
			lastName += ")";
		}

		if (firstName.empty()) {
			if (lastName.empty()) {
				return "Incognito";
			} else {
				return lastName + " with unknown first name";
			}
		} else {
			if (lastName.empty()) {
				return firstName + " with unknown last name";
			} else {
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
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1970, "Appolinaria");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeLastName(1968, "Volkova");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1990, "Polina");
	  person.ChangeLastName(1990, "Volkova-Sergeeva");
	  cout << person.GetFullNameWithHistory(1990) << endl;

	  person.ChangeFirstName(1966, "Pauline");
	  cout << person.GetFullNameWithHistory(1966) << endl;

	  person.ChangeLastName(1960, "Sergeeva");
	  for (int year : {1960, 1967}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeLastName(1961, "Ivanova");
	  cout << person.GetFullNameWithHistory(1967) << endl;

	  return 0;

}
