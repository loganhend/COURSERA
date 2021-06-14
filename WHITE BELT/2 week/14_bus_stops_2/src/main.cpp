//==================================================================================
// Description : Week 2. Programming Assignment. Bus stops. Part 2
//==================================================================================

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
	int queries;
	cin >> queries;
	int stopCount,busNumber;
	busNumber = 1;
	string stopName;
	map<vector<string>,int> busList;
	for (int i=0; i < queries; ++i) {
		cin >> stopCount;
		vector<string> stopList;
		for (int j=0; j < stopCount; ++j) {
			cin >> stopName;
			stopList.push_back(stopName);
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
