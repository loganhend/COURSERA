#include "responses.h"

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
