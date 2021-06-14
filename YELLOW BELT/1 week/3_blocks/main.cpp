#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint64_t s = 0;
    uint64_t n, p = 0;
    cin >> n >> p;
    for (int i=0; i<n; ++i){
        uint64_t a,b,c = 0;
        cin >> a >> b >> c;
        s += p * a * b * c;
    }
    cout << s << endl;
    return 0;
}
