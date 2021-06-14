#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    string input_line;
    if (input) {
        while(getline(input,input_line)) {
            output << input_line << endl;
        }
    } else {
        cout << "error!" << endl;
    }
    return 0;
}
