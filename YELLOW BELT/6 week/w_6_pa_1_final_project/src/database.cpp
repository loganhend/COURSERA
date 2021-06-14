#include "database.h"

#include <iostream>

void Database::Add(const Date& date, const string& event) {
    if (!unique_db[date].count(event)) {
        db[date].push_back(event);
        unique_db[date].insert(event);
    }
}

void Database::Print(ostream& os) const {
    for (const auto& [date, events] : db) {
        for (const auto& event : events) {
            os << date << " " << event << endl;
        }
    }
}

pair<Date, string> Database::Last(const Date& date) const {
    if (db.empty() || date < db.begin()->first) {
        throw invalid_argument("No entries");
    }

    auto it = prev(db.upper_bound(date));

    return make_pair(it->first, it->second.back());
}
