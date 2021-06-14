#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(vector<int> inp) {
	auto result = find_if(begin(inp),end(inp),[](const int val){
		return val < 0;
	});
	auto it = result;
	while ( it != begin(inp)) {
		--it;
		cout << *it << " ";
	}
}

int main() {
	PrintVectorPart({6, 1, 8, -5, 4});
	cout << endl;
	PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	cout << endl;
	PrintVectorPart({6, 1, 8, 5, 4});
	cout << endl;
	return 0;
}
