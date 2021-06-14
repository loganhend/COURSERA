#include <iostream>
#include <string>


using namespace std;

class ReversibleString {
private:
	string stateStr;
public:
	ReversibleString(string s) {
		stateStr = s;
	}
	ReversibleString() {
		stateStr = "";
	}
	void Reverse() {
		string tt = stateStr;
		for (int k = 0; k<stateStr.size(); ++k) {
			tt[k] = stateStr[stateStr.size()-1-k];
		}
		stateStr = tt;
	}
	string ToString() const{
		return stateStr;
	}
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
