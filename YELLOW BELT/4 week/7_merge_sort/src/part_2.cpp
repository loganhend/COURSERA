#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	//cout << diff << endl;
	if (range_end - range_begin >= 3) {
		vector<typename RandomIt::value_type> elements(range_begin, range_end);
		auto part_1 = begin(elements) + (range_end - range_begin) / 3;
		auto part_2 = part_1 + (range_end - range_begin) / 3;
		MergeSort(begin(elements), part_1);
		MergeSort(part_1, part_2);
		MergeSort(part_2, end(elements));
		vector<typename RandomIt::value_type> result;
		merge(begin(elements), part_1, part_1, part_2, back_inserter(result));
		merge(begin(result), end(result), part_2, end(elements), range_begin);
	}

}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}


