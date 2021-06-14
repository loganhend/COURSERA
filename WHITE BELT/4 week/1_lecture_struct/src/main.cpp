#include <iostream>
#include <string>
using namespace std;

struct Specialization{
	string value;
	explicit Specialization(string set_value) {
		value = set_value;
	}
};

struct Week{
	string value;
	explicit Week(string set_value) {
		value = set_value;
	}
};

struct Course{
	string value;
	explicit Course(string set_value) {
		value = set_value;
	}
};

struct LectureTitle{
	string specialization;
	string course;
	string week;
	LectureTitle(const Specialization& specialization_value,
				 const Course& course_value,
				 const Week& week_value) {
		specialization = specialization_value.value;
		course = course_value.value;
		week = week_value.value;
	}
};

int main() {
	LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);
	return 0;
}
