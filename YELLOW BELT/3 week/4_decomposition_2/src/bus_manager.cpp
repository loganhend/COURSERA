#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	// Реализуйте этот метод
	buses_to_stops[bus] = stops;
	for (const string& stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	// Реализуйте этот метод
	if (stops_to_buses.count(stop)==0) {
		return {};
	}
	vector<string> buses = stops_to_buses.at(stop);
	return {buses};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	// Реализуйте этот метод
	if (buses_to_stops.count(bus) == 0) {
		return {};
	}
	return {bus,buses_to_stops.at(bus),stops_to_buses};
}

AllBusesResponse BusManager::GetAllBuses() const {
	// Реализуйте этот метод
	return {buses_to_stops};
}
