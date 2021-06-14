#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};


void TestTwoRoots() {
	AssertEqual(GetDistinctRealRootCount(2,5,-3),2,"TestTwoRoots");
}

void TestOneRoot() {
	AssertEqual(GetDistinctRealRootCount(1,4,4),1,"TestOneRoot");
}

void TestZeroRoot() {
	AssertEqual(GetDistinctRealRootCount(1,3,4),0,"TestOneRoot");
}

void TestAZero() {
	AssertEqual(GetDistinctRealRootCount(0,6,-3),1,"TestAZero");
}

void TestBZero() {
	AssertEqual(GetDistinctRealRootCount(2,0,-18),2,"TestBZero");
}

void TestCZero() {
	AssertEqual(GetDistinctRealRootCount(2,4,0),2,"TestCZero");
}

void TestABZero() {
	AssertEqual(GetDistinctRealRootCount(0,0,100),0,"TestCZero");
}

void TestACZero() {
	AssertEqual(GetDistinctRealRootCount(0,2,0),1,"TestCZero");
}

void TestBCZero() {
	AssertEqual(GetDistinctRealRootCount(2,0,0),1,"TestCZero");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestTwoRoots,"TestTwoRoots");
  runner.RunTest(TestOneRoot,"TestOneRoot");
  runner.RunTest(TestZeroRoot,"TestZeroRoot");
  runner.RunTest(TestAZero,"TestAZero");
  runner.RunTest(TestBZero,"TestBZero");
  runner.RunTest(TestCZero,"TestCZero");
  runner.RunTest(TestABZero,"TestABZero");
  runner.RunTest(TestACZero,"TestACZero");
  runner.RunTest(TestBCZero,"TestBCZero");

  // добавьте сюда свои тесты
  return 0;
}
