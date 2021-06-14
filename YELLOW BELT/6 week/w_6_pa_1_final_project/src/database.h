#pragma once

#include "date.h"

#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& os) const;

    template <class Predicate>
    int RemoveIf(Predicate p) {
        int removed = 0;
        map<Date, vector<string>::iterator> to_delete;

        for (auto& item : db) {
            auto& date = item.first;
            auto& events = item.second;

            auto p_ = [&p, &date] (const string& event) {
                return !p(date, event);
            };

            auto del_it = stable_partition(begin(events), end(events), p_);

            to_delete[date] = del_it;

        }

        for (auto& [date, del_it]: to_delete) {
            removed += end(db[date]) - del_it;
            db[date].erase(del_it, end(db[date]));
            unique_db[date] = set<string>(begin(db[date]), end(db[date]));
            if (db[date].empty()) {
                db.erase(date);
                unique_db.erase(date);
            }
        }

        return removed;
    }

    template <class Predicate>
    vector<pair<Date, string>> FindIf(Predicate p) const {
        vector<pair<Date, string>> found;

        for (const auto& item : db) {
            auto& date = item.first;
            auto& events = item.second;

            auto p_ = [&p, &date] (const string& event) {
                return p(date, event);
            };

            for (auto event_it = find_if(begin(events), end(events), p_);
                 event_it != end(events);
                 event_it = find_if(next(event_it), end(events), p_)) {
                found.push_back(make_pair(date, *event_it));
            }
        }
        return found;
    }

    pair<Date, string> Last(const Date& date) const;
private:
    map<Date, vector<string>> db;
    map<Date, set<string>> unique_db;
};
