#include "query.h"

istream& operator >> (istream& is, Query& q) {
	// Реализуйте эту функцию
	string operation_code;
	is >> operation_code;
	if (operation_code == "NEW_BUS") {

		string new_bus;
		is >> new_bus;
		int stop_count;
		is >> stop_count;
		vector<string> stops;
		stops.resize(stop_count);
		for (string& stop : stops) {
			is >> stop;
		}
		q = {QueryType::NewBus,new_bus,"",stops};
	} else if (operation_code == "BUSES_FOR_STOP") {
		string stop;
		is >> stop;
		q = {QueryType::BusesForStop,"",stop,{}};
	} else if (operation_code == "STOPS_FOR_BUS") {
		string bus;
		is >> bus;
		q = {QueryType::StopsForBus,bus,"",{}};
	} else if (operation_code == "ALL_BUSES") {
		q = {QueryType::AllBuses,"","",{}};
	}
	return is;
}
