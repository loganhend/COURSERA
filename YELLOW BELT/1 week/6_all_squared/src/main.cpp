#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

//template <class First, class Second> pair<First, Second> operator * (pair<First,Second> lhr, pair<First,Second> rhr);
template <class T> T Sqr(T val);
template <class T> vector<T> Sqr(vector<T>& collection);
template <class First, class Second> map<First, Second> Sqr(map<First,Second>& collection);
template <class First, class Second> pair<First,Second> Sqr(pair<First,Second> collection);
/*
template <class First, class Second>
pair<First, Second> operator * (pair<First,Second> lhr, pair<First,Second> rhr) {
	return make_pair(
				lhr.first*rhr.first,
				lhr.second*rhr.second
			);
}
*/

template <class T>
T Sqr(T val) {
	return val*val;
}

template <class T>
vector<T> Sqr(vector<T>& collection) {
	for (auto& item: collection) {
		item = Sqr(item);
	}
	return collection;
}

template <class First, class Second>
map<First, Second> Sqr(map<First,Second>& collection) {
	for (auto& item: collection) {
			item.second = Sqr(item.second);
	}
	return collection;
}

template <class First, class Second>
pair<First,Second> Sqr(pair<First,Second> collection) {
	return make_pair(Sqr(collection.first),Sqr(collection.second));
}


int main() {
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

	return 0;
}
