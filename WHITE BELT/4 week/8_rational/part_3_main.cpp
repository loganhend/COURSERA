#include <iostream>
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

// Реализуйте для класса Rational операторы * и /

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}