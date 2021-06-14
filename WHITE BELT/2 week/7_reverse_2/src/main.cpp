//==================================================================================
// Description : Week 2. Reverse number sequence Programming Assignment
//==================================================================================


#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> reversedV;
	for (int i = (v.size()-1); i >= 0; --i) {
		reversedV.push_back(v[i]);
	}
	return reversedV;
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2}; // @suppress("Invalid arguments")
	vector<int> reversed = Reversed(numbers);
	for (auto n : reversed) {
		cout << n << endl;
	}

	return 0;
}
