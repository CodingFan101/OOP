// Christopher Hainzl
// rational.h

#ifndef __RATIONAL__
#define __RATIONAL__

#include <iostream>
#include <string>
using namespace std;

class Rational_Error {
private:
    string err_msg;
public:
    Rational_Error(const string& s) : err_msg(s) {}
    string get_message() { return err_msg; }
};

class Rational {
private:
    int num, denom;
    void simplify(); //Reduces fraction to lowest terms
public:
    Rational(int n = 0, int d = 1);
    Rational(const string&);
    Rational& operator+=(const Rational&);
    Rational& operator-=(const Rational&);
    Rational& operator*=(const Rational&);
    Rational& operator/=(const Rational&);
    int numerator() const { return num; }
    int denominator() const { return denom; }
    operator double() const;
};

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

istream& operator>>(istream& is, Rational& r);
ostream& operator<<(ostream& os, const Rational& r);

double Power(double base, const Rational& r);
int floor(const Rational& r);
int ceil(const Rational& r);
int round(const Rational& r);
Rational RationalPower(const Rational& r, int n);
string to_s(const Rational& r);

#endif
