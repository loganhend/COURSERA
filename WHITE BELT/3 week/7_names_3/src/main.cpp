#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
	map<int,string> FirstNames;
	map<int,string> LastNames;
	int birthYear = 0;
	string findChangeByYear(int year, const map<int,string>& namesSet) const {
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
	vector<string> inverseVector(const vector<string>& inputVector) const{
		vector<string> inversed;
		for (int k=inputVector.size()-1; k>=0;--k) {
			inversed.push_back(inputVector[k]);
		}
		return inversed;
	}
	vector<string> findChangeHistory (int year, map<int,string> namesSet, string currentName) const {
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
	Person(){}
	Person(string first_name, string last_name, int birth_year){
		ChangeFirstName(birth_year, first_name);
		ChangeLastName(birth_year, last_name);
		birthYear = birth_year;
	}
	void ChangeFirstName(int year, const string& first_name){
		if (year > birthYear) {
			FirstNames[year] = first_name;
		}
	}
	void ChangeLastName(int year, const string& last_name){
		if (year > birthYear) {
			LastNames[year] = last_name;
		}
	}
	string GetFullName(int year) const{
		string firstName,lastName;
		firstName = findChangeByYear(year,FirstNames);
		lastName = findChangeByYear(year,LastNames);
		if (firstName.empty()) {
			return "No person";
		} else {
			return firstName + " " + lastName;
		}

	}
	string GetFullNameWithHistory(int year) const{
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
			return "No person";
		} else {
			return firstName + " " + lastName;
		}
	}
};

int main() {

	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;

}
