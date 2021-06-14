#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> temps(n);
    int64_t sumTemp = 0;
    for (auto& t : temps) {
        cin >> t;
        sumTemp += t;
    }
    vector<int> hotDays;
    int64_t avgTemp = sumTemp/n;
    for (int i=0; i<n; ++i) {
        if (temps[i] > avgTemp) {
            hotDays.push_back(i);
        }
    }
    cout << hotDays.size() << endl;
    for (int d : hotDays) {
        cout << d << " ";
    }

}
