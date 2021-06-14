//==================================================================================
// Description : Week 2. Move all values to one vector Programming Assignment
//==================================================================================


#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto str : source) {
		destination.push_back(str);
	}
	source.clear();
}

int main() {
	vector<string> source = {"a", "b", "c"}; // @suppress("Invalid arguments")
	vector<string> destination = {"z"}; // @suppress("Invalid arguments")
	MoveStrings(source, destination);
	for (auto str : destination) {
		cout << str << endl;
	}
	return 0;
}
