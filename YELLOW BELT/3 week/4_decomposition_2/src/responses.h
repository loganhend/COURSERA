#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct BusesForStopResponse {
	// Наполните полями эту структуру
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	// Наполните полями эту структуру
	string bus;
	vector<string> stop_list;
	map<string, vector<string> > stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	map<string, vector<string> > buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
