#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
	auto right_element = numbers.lower_bound(border);
	if (right_element == numbers.begin()) {
		return right_element;
	}
	auto left_element = prev(right_element);
	if (right_element == numbers.end()) {
		return left_element;
	}
	//cout << border << " left: " << *left_element << " right: "<< *right_element << endl;
	if (*right_element - border >= border - *left_element) {
		return left_element;
	} else {
		return right_element;
	}
}


int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
