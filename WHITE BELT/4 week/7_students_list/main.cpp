#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int dayBirth;
    int monthBirth;
    int yearBirth;
};

int main() {
    vector<Student> students_list;
    int students_number, requests_number;
    string student_first_name, student_last_name;
    int student_day_birth,student_month_birth,student_year_birth;
    cin >> students_number;
    for (int i = 0 ; i < students_number; ++i) {
        cin >> student_first_name;
        cin >> student_last_name;
        cin >> student_day_birth;
        cin >> student_month_birth;
        cin >> student_year_birth;
        students_list.push_back({student_first_name,student_last_name,student_day_birth,student_month_birth,student_year_birth});
    }

    cin >> requests_number;
    string op;
    Student selected_student;
    int k;
    for (int j = 0; j < requests_number; ++j) {
        cin >> op;
        //cout << op << ": ";
        if (op == "name") {
            cin >> k;
            if (k <= 0 | k > students_number) {
                cout << "bad request" << endl;
                continue;
            }
            selected_student = students_list[k-1];
            cout << selected_student.firstName << " "
            << selected_student.lastName << endl;
        } else if (op == "date") {
            cin >> k;
            if (k <= 0 | k > students_number) {
                cout << "bad request" << endl;
                continue;
            }
            selected_student = students_list[k-1];
            cout << selected_student.dayBirth << "."
                 << selected_student.monthBirth << "."
                 << selected_student.yearBirth << endl;
        } else {
            cin >> k;
            cout << "bad request" << endl;
        }
    }
    return 0;
}
