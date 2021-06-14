#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int denom) {
        if (denom == 0) throw invalid_argument("denominator equals 0");
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

Rational operator / (const Rational& lhr, const Rational& rhr) {
    if (lhr.Denominator()*rhr.Numerator() == 0) {
        throw domain_error("denominator equals 0");
    }
    return Rational(lhr.Numerator()*rhr.Denominator(), lhr.Denominator()*rhr.Numerator());
}

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

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}