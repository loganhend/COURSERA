#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    int m,n,c;
    if (input) {
        input >> m;
        input.ignore(1);
        input >> n;
        input.ignore(1);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                input >> c;
                input.ignore(1);
                cout << setw(10) << c;
                if (j < (n-1)) {
                    cout << " ";
                }
            }
            if (i < (m-1)) {
                cout << endl;
            }
        }
    }

    return 0;
}
