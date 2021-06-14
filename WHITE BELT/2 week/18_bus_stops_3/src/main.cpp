//==================================================================================
// Description : Week 2. Programming Assignment. Bus stops. Part 3
//==================================================================================

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
	int queries;
	cin >> queries;
	int stopCount,busNumber;
	busNumber = 1;
	string stopName;
	map<set<string>,int> busList;
	for (int i=0; i < queries; ++i) {
		cin >> stopCount;
		set<string> stopList;
		for (int j=0; j < stopCount; ++j) {
			cin >> stopName;
			stopList.insert(stopName);
		}
		if (busList.count(stopList)==0) {
			busList[stopList] = busNumber;
			cout << "New bus " << busNumber << endl;
			busNumber++;
		} else {
			cout << "Already exists for " << busList[stopList] << endl;
		}
	}

	return 0;
}
