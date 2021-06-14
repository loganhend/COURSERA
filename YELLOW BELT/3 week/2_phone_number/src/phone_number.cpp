#include "phone_number.h"
#include <sstream>
#include <iostream>
using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
	istringstream ss(international_number);
	char c;
	ss.get(c);
	if (c != '+') {
		throw invalid_argument("");
	}
	getline(ss,PhoneNumber::country_code_,'-');
	if (PhoneNumber::country_code_.empty()) {
		throw invalid_argument("");
	}
	getline(ss,PhoneNumber::city_code_,'-');
	if (PhoneNumber::city_code_.empty()) {
			throw invalid_argument("");
		}
	getline(ss,PhoneNumber::local_number_);
	if (PhoneNumber::local_number_.empty()) {
			throw invalid_argument("");
		}
	cout << ss.str() << endl;
}

string PhoneNumber::GetCountryCode() const {
	return PhoneNumber::country_code_;
}
string PhoneNumber::GetCityCode() const {
	return PhoneNumber::city_code_;
}
string PhoneNumber::GetLocalNumber() const {
	return PhoneNumber::local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
	ostringstream ss;
	ss << "+" << PhoneNumber::country_code_ << "-"
			<< PhoneNumber::city_code_ << "-"
			<< PhoneNumber::local_number_;
	return ss.str();
}
