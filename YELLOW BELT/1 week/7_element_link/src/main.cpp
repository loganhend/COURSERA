#include <iostream>
#include <map>
#include <string>
using namespace std;

template <class K, class V>
V& GetRefStrict (map<K,V>& collection, K key) {
	if (collection.count(key) == 0) {
		throw runtime_error("");
	}
	V& val = collection.at(key);
	return val;
}


int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}
