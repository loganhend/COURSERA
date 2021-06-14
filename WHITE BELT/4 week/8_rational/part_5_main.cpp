#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int denom) {
        int nod = 0;
        nod = NOD(num,denom);
        if (num < 0 && denom < 0) {
            nod = -nod;
        } else if (denom < 0) {
            denom = -denom;
            num = -num;
        }
        numerator = num / nod;
        denominator = denom / nod;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator, denominator;
    int NOD(int a , int b) {
        int minNum;
        a = abs(a);
        b = abs(b);
        while (a > 0 && b >0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        return a+b;
    }
};

// Реализуйте для класса Rational операторы ==, + и -
bool operator == (const Rational& lhr, const Rational& rhr) {
    if (lhr.Numerator() != rhr.Numerator()) {
        return false;
    }
    if (lhr.Denominator() != rhr.Denominator()) {
        return false;
    }
    return true;
}

Rational operator + (const Rational& lhr, const Rational& rhr) {
    if (lhr.Denominator()!=rhr.Denominator()) {
        return Rational(lhr.Numerator()*rhr.Denominator() + rhr.Numerator()*lhr.Denominator(), lhr.Denominator()*rhr.Denominator());
    } else {
        return Rational(lhr.Numerator() + rhr.Numerator(), lhr.Denominator());
    };
}

Rational operator - (const Rational& lhr, const Rational& rhr) {
    if (lhr.Denominator()!=rhr.Denominator()) {
        return Rational(lhr.Numerator()*rhr.Denominator() - rhr.Numerator()*lhr.Denominator(), lhr.Denominator()*rhr.Denominator());
    } else {
        return Rational(lhr.Numerator() - rhr.Numerator(), lhr.Denominator());
    };
}

Rational operator * (const Rational& lhr, const Rational& rhr) {
    return Rational(lhr.Numerator()*rhr.Numerator(), lhr.Denominator()*rhr.Denominator());
}

Rational operator / (const Rational& lhr, const Rational& rhr) {
    return Rational(lhr.Numerator()*rhr.Denominator(), lhr.Denominator()*rhr.Numerator());
}

istream& operator>>(istream& stream, Rational& rational){
    int n = rational.Numerator(), d = rational.Denominator();
    if(stream){
        stream >> n;
        stream.ignore(1);
        stream >> d;
    }
    rational = Rational{n, d};
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

bool operator < (const Rational& lhr, const Rational& rhr) {
    if (lhr.Denominator() == rhr.Denominator() ) {
        return lhr.Numerator() < rhr.Numerator();
    } else {
        return lhr.Numerator()*rhr.Denominator() < rhr.Numerator()*lhr.Denominator();
    }
}
// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}