#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    string input_line;
    if (input) {
        while(getline(input,input_line)) {
            cout << input_line << endl;
        }
    } else {
        cout << "error!" << endl;
    }
    return 0;
}