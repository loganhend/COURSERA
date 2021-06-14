//==================================================================================
// Description : Week 2. Programming Assignment. Bus stops. Part 1
//==================================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int queries;
	cin >> queries;
	string op,busNumber,stopName;

	int addStopsCnt;
	map< string,vector<string> > busStops;
	map< string,vector<string> > stopBusses;
	vector<string> busList;

	for (int i=0; i<queries; ++i) {
		cin >> op;
		if (op=="NEW_BUS") {
			cin >> busNumber >> addStopsCnt;
			busList.push_back(busNumber);
			vector<string> stopsVec;
			for (int j=0; j < addStopsCnt; ++j) {
				cin >> stopName;
				stopsVec.push_back(stopName);
				stopBusses[stopName].push_back(busNumber);
			}
			busStops[busNumber] = stopsVec;
			continue;
		}
		if (op=="BUSES_FOR_STOP") {
			cin >> stopName;
			if (stopBusses.count(stopName) == 0) {
				cout << "No stop" << endl;
			} else {
				for (auto bus: (stopBusses[stopName])) {
					cout << bus << " ";
				}
				cout << endl;
			}
			continue;
		}
		if (op == "STOPS_FOR_BUS") {
			cin >> busNumber;
			if (busStops.count(busNumber) == 0) {
				cout << "No bus" << endl;
			} else {
				for (auto stopName: busStops[busNumber]) {
					cout << "Stop " << stopName << ": ";
					if (stopBusses[stopName].size() == 1) {
						cout << "no interchange" << endl;
					} else {
						for (auto bus: stopBusses[stopName]) {
							if (bus != busNumber) {
								cout << bus << " ";
							}
						}
						cout << endl;
					}
				}
			}
			continue;
		}
		if (op == "ALL_BUSES") {
			if (busList.empty()) {
				cout << "No buses" << endl;
			} else {
			sort(busList.begin(), busList.end());
			for (auto busName: busList) {
				cout << "Bus " << busName << ": ";
				for (auto stopName: busStops[busName]) {
					cout << stopName << " ";
				}
				cout << endl;
			}
			}
		}
	}

	return 0;

}
