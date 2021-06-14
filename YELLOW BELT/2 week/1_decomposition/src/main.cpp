#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

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

struct BusesForStopResponse {
	// Наполните полями эту структуру
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	// Реализуйте эту функцию
	if (r.buses.size() == 0) {
		os << "No stop";
	} else {
		for (const string& bus : r.buses) {
			os << bus << " ";
		}
	}
	return os;
}

struct StopsForBusResponse {
	// Наполните полями эту структуру
	string bus;
	vector<string> stop_list;
	map<string, vector<string> > stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	// Реализуйте эту функцию
	if (r.stop_list.size() == 0) {
		os << "No bus";
	} else {
		size_t i = 0;
		for (const string& stop : r.stop_list) {
			os << "Stop " << stop << ": ";
			if (r.stops.at(stop).size() == 1) {
				os << "no interchange";
			} else {
				for (const string& other_bus : r.stops.at(stop)) {
					if (r.bus != other_bus) {
						os << other_bus << " ";
					}
				}
			}
			i++;
			if (i != r.stop_list.size()) {
				os << endl;
			}
		}
	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string> > buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	// Реализуйте эту функцию
	if (r.buses.empty()) {
		os << "No buses";
	} else {
		size_t buses_count = r.buses.size();
		size_t i = 0;
		for (const auto& bus_item : r.buses) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			}
			i++;
			if (i != buses_count) {
				os << endl;
			}
		}
	}
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		// Реализуйте этот метод
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		// Реализуйте этот метод
		if (stops_to_buses.count(stop)==0) {
			return {};
		}
		vector<string> buses = stops_to_buses.at(stop);
		return {buses};
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		// Реализуйте этот метод
		if (buses_to_stops.count(bus) == 0) {
			return {};
		}
		return {bus,buses_to_stops.at(bus),stops_to_buses};
	}

	AllBusesResponse GetAllBuses() const {
		// Реализуйте этот метод
		return {buses_to_stops};
	}
private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
