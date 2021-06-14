#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    double input_value;
    if (input) {
        cout << fixed << setprecision(3);
        while (input >> input_value) {
            cout << input_value << endl;
        }
    }
    return 0;
}
