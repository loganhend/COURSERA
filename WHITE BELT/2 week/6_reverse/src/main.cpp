//==================================================================================
// Description : Week 2. Reverse number sequence Programming Assignment
//==================================================================================

#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
	int vSize = v.size();
	if (vSize>1) {
		for (int i = 0; i < (vSize / 2); ++i) {
				int tmp = v[i];
				v[i] = v[vSize-1-i];
				v[vSize-1-i] = tmp;
			}
	}
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2}; // @suppress("Invalid arguments")
	Reverse(numbers);
	for (auto n : numbers) {
		cout << n << endl;
	}
}
