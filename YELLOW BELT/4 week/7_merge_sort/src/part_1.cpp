#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	auto diff = range_end - range_begin;
	if (diff >= 2) {
		vector<typename RandomIt::value_type> elements(range_begin, range_end);
		auto middle =  begin(elements) + diff / 2;
		MergeSort(begin(elements), middle);
		MergeSort(middle, end(elements));
		merge(begin(elements), middle, middle, end(elements), range_begin);
	}

}

/*
int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
*/

