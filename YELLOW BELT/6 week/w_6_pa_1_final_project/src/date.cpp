#include "date.h"
#include <iomanip>
#include <tuple>

using namespace std;

ostream& operator << (ostream& os, const Date& date) {
	os << setw(4) << setfill('0') << date.year << "-"
			<< setw(2) << setfill('0') << date.month << "-"
			<< setw(2) << setfill('0') << date.day;
	return os;
}

bool operator == (const Date& lhs, const Date& rhs) {
		return tie(lhs.year,lhs.month,lhs.day) == tie(rhs.year,rhs.month,rhs.day);
}

bool operator != (const Date& lhs, const Date& rhs) {
		return tie(lhs.year,lhs.month,lhs.day) != tie(rhs.year,rhs.month,rhs.day);
}

bool operator < (const Date& lhs, const Date& rhs) {
		return tie(lhs.year,lhs.month,lhs.day) < tie(rhs.year,rhs.month,rhs.day);
}

bool operator <= (const Date& lhs, const Date& rhs) {
		return tie(lhs.year,lhs.month,lhs.day) <= tie(rhs.year,rhs.month,rhs.day);
}

bool operator > (const Date& lhs, const Date& rhs) {
		return tie(lhs.year,lhs.month,lhs.day) > tie(rhs.year,rhs.month,rhs.day);
}

bool operator >= (const Date& lhs, const Date& rhs) {
		return tie(lhs.year,lhs.month,lhs.day) >= tie(rhs.year,rhs.month,rhs.day);
}

Date ParseDate(istream& is) {
	Date date;
	is >> date.year;
	is.ignore(1);
	is >> date.month;
	is.ignore(1);
	is >> date.day;
	return date;
}

