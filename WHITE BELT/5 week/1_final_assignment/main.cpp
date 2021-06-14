#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;

struct Day {
    int value;
};

struct Month {
    int value;
};

struct Year {
    int value;
};

class Date {
public:
    explicit Date(Year y, Month m, Day d) {
        CheckMonth(m.value);
        CheckDay(d.value);

        month = m.value;
        year = y.value;
        day = d.value;
    }

    int GetYear() const {
        return year;
    };
    int GetMonth() const {
        return month;
    };
    int GetDay() const {
        return day;
    };
private:
    int year;
    int month;
    int day;
    bool CheckMonth(int mon) {
        if (mon > 12 || mon < 1) {
            throw runtime_error("Month value is invalid: "+to_string(mon));
        }
        return true;
    }
    bool CheckDay(int d) {
        if (d > 31 || d < 1) {
            throw runtime_error("Day value is invalid: "+to_string(d));
        }
        return true;
    }
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

ostream& operator<<(ostream& stream, const Date& date){
    stream << setfill('0')
         << setw(4) << date.GetYear() << '-'
         << setw(2) << date.GetMonth() << '-'
         << setw(2) << date.GetDay();
    return stream;
}

void CheckDelimiter(istream &input, const string &new_date){
    int c = input.get();
    if(c != '-'){
        throw runtime_error("Wrong date format: " + new_date);
    }
    c = input.get();
    if(!isdigit(c) || c == '-'){
        if(!isdigit(input.peek())){
            throw runtime_error("Wrong date format: " + new_date);
        }
    }
    input.putback(char(c));
}

Date ParseDate(const string& input_str) {
    stringstream input_ss(input_str);
    int year,month,day;
    string end;
    if (input_ss) {
        input_ss >> year;
        CheckDelimiter(input_ss, input_str);
        input_ss >> month;
        CheckDelimiter(input_ss, input_str);
        input_ss >> day;
        input_ss >> end;
        if(!end.empty()){
            throw runtime_error("Wrong date format: " + input_str);
        }
        return Date({year},{month},{day});
    }
}



class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        data[date].insert(event);
    }
    void DeleteEvent(const Date& date, const string& event) {
        if (data.count(date) > 0 ) {
            if (data[date].count(event) > 0 ) {
                data[date].erase(event);
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Event not found" << endl;
            }
        } else {
            cout << "Event not found" << endl;
        }
    }
    void DeleteDate(const Date& date) {
        int event_number = 0;
        if (data.count(date) > 0 ) {
            event_number = data[date].size();
            data[date].clear();
        }
        cout << "Deleted " << event_number <<" events" << endl;
    }

    void Find(const Date& date) const {
        if (data.count(date) > 0 ) {
            for (auto s: data.at(date)) {
                cout << s << endl;
            }
        }
    }

    void Print() const{
        for(const auto& item : data){
            for(const auto& event : item.second){
                cout << item.first << " ";
                cout << event << endl;
            }
        }
    }
private:
    map<Date, set<string> > data;
};

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        try {
            if (!command.empty()) {
                stringstream ss(command);
                if (ss) {
                    string op;
                    ss >> op;
                    if (op == "Add") {
                        string d;
                        ss >> d;
                        Date date = ParseDate(d);
                        string event;
                        ss >> event;
                        db.AddEvent(date, event);
                        continue;
                    } else if (op == "Del") {
                        string d;
                        ss >> d;
                        Date date = ParseDate(d);
                        string event;
                        ss >> event;
                        if (event.empty()) {
                            db.DeleteDate(date);
                        } else {
                            db.DeleteEvent(date, event);
                        }
                        continue;
                    } else if (op == "Print") {
                        db.Print();
                        continue;
                    } else if (op == "Find") {
                        string d;
                        ss >> d;
                        Date date = ParseDate(d);
                        db.Find(date);
                        continue;
                    } else {
                        throw runtime_error("Unknown command: " + op);
                    }
                }
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
