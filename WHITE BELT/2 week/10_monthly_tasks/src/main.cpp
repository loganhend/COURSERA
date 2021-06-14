//==================================================================================
// Description : Week 2. Programming Assignment. Monthly task list
//==================================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main() {
	int q;
	cin >> q;

	string op;
	int num;
	string desc;

	int currentMonth = 1;
	vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // @suppress("Invalid arguments")
	vector<vector<string>> taskList(daysInMonth[currentMonth-1]);

	for (int i=1; i<=q; ++i) {
		cin >> op;
		if (op == "ADD") {
			cin >> num >> desc;
			//cout << i << ": " << op << " - " << num << " - " << desc << endl;
			taskList[num-1].push_back(desc);
		}
		if (op == "DUMP") {
			cin >> num;
			vector<string> tasks = taskList[num-1];
			cout << tasks.size() << " ";
			for (string task: tasks) {
				cout << task << " ";
			}
			cout << endl;
		}
		if (op == "NEXT") {
			int nextMonth = currentMonth + 1;
			if (nextMonth>12) {
				nextMonth = 1;
			}
			int currentDays = daysInMonth[currentMonth-1];
			int nextDays = daysInMonth[nextMonth-1];
			if (currentDays <= nextDays) {
					taskList.resize(nextDays);
			} else {
				vector<vector<string>> newTaskList =  taskList;// @suppress("Invalid arguments")
				newTaskList.resize(nextDays);
				vector<string>& newLastDay = newTaskList[nextDays-1];
				for (int d = nextDays; d < currentDays; ++d) {
					vector<string> oldLastDay = taskList[d];
					newLastDay.insert(end(newLastDay), begin(oldLastDay), end(oldLastDay));
				}
				taskList = newTaskList;
			}
			currentMonth = nextMonth;
		}
	}
}
