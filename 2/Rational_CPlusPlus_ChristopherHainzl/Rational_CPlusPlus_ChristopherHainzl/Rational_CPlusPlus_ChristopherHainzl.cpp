// This should be in its own .cpp file
// rational.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Rational.h"
using namespace std;

static int gcd(int x, int y);

void Rational::simplify()
{
    int d = gcd(abs(num), denom);
    num /= d;
    denom /= d;
}

Rational::Rational(int n, int d) :num(n), denom(d)
{
    if (denom == 0)
        throw Rational_Error("Divide-by-zero");
    if (denom < 0) {
        denom *= -1;
        num *= -1;
    }
    simplify();
}

Rational::Rational(const string& str)
{ //Assumes string in form "num/denom"
    static const string validchar = "-0123456789";
    int index;

    num = atoi(str.c_str());
    index = str.find('/');

    if ((num == 0 && str.find_first_of(validchar) != 0)
        || (index == string::npos)
        || (index != str.find_first_not_of(validchar))
        || (str.find_first_not_of(validchar, index + 1) != string::npos))

        throw Rational_Error("Invalid fraction");

    denom = atoi(str.c_str() + index + 1);
    if (denom == 0)
        throw Rational_Error("Divide-by-zero");
    simplify();
}

Rational::operator double() const
{
    return static_cast<double>(num) / denom;
}

Rational& Rational::operator+=(const Rational& s)
{
    num = num * s.denom + denom * s.num;
    denom *= s.denom;
    simplify();
    return *this;
}

Rational& Rational::operator-=(const Rational& s)
{
    num = num * s.denom - denom * s.num;
    denom *= s.denom;
    simplify();
    return *this;
}

Rational& Rational::operator*=(const Rational& s)
{
    num *= s.num;
    denom *= s.denom;
    simplify();
    return *this;
}
Rational& Rational::operator/=(const Rational& s)
{
    if (s.num == 0)
        throw Rational_Error("Divide-by-zero");
    num *= s.denom;
    denom *= s.num;
    simplify();
    return *this;
}

Rational operator+(const Rational& r, const Rational& s)
{
    Rational t = r;

    return t += s;
}

Rational operator-(const Rational& r, const Rational& s)
{
    Rational t = r;

    return t -= s;
}

Rational operator*(const Rational& r, const Rational& s)
{
    Rational t = r;

    return t *= s;
}

Rational operator/(const Rational& r, const Rational& s)
{
    Rational t = r;

    return t /= s;
}

istream& operator>>(istream& is, Rational& r)
{
    char c;
    int n, d;

    is >> n >> c >> d;
    if (!is || c != '/')
        throw Rational_Error("Invalid fraction");
    else r = Rational(n, d);
    return is;
}

ostream& operator<<(ostream& os, const Rational& r)
{
    return os << r.numerator() << '/' << r.denominator();
}

int gcd(int x, int y)
{
    int r;

    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

double Power(double base, const Rational& r)
{
	double result = 1;

	Rational t = r;
	double numerator = t.numerator(), denominator = t.denominator();
	double power = numerator / denominator;
    if (base > 0) {
        if (denominator == 0) {
			throw Rational_Error("Divide-by-zero");
		}
		else {
            result = pow(base, power);
        }
    }
    else if (base == 0) {
        if (power > 0) {
            result = 0;
        }
        if (power < 0) {
			throw Rational_Error("Indeterminate number");
        }
        else if (numerator == 0) {
			throw Rational_Error("Indeterminate number");
        }
        else if (denominator == 0) {
            throw Rational_Error("Divide-by-zero");
        }
    }
    else if (base < 0) {
        if (denominator == 0) {
            throw Rational_Error("Divide-by-zero");
        }
		if (int(denominator) % 2 == 0) {
            throw Rational_Error("Imaginary number");
        }
        else {
            result = -1 * pow(abs(base), power);
        }
    }
	return result;
}

int floor(const Rational& r) {
    Rational t = r;
    int result = t.numerator() / t.denominator();
    if (result <= 0 && (t.numerator() < 0 || t.denominator() < 0)) {
        result--;
    }
    return result;
}

int ceil(const Rational& r) {
	Rational t = r;
	int result = t.numerator() / t.denominator();
	if ((t.numerator() % t.denominator() != 0) && result > 0) {
		result++;
	}
	return result;
}

int round(const Rational& r) {
	Rational t = r;
    double numerator = t.numerator(), denominator = t.denominator();
    double quotient = numerator / denominator;
    int result = 0;
    if (quotient < 0) {
        result = int(quotient - 0.5);
    }
    else {
        result = int(quotient + 0.5);
    }
	return result;
}

Rational RationalPower(const Rational& r, int n) {
    Rational t = r;
    double original_numerator = t.numerator(), original_denominator = t.denominator(), new_numerator = 0, new_denominator = 0;
    if (original_numerator == 0 && n <= 0) {
        throw Rational_Error("Divide-by-zero");
    }
    else if (n < 0) {
		new_numerator = -1 * pow(original_denominator, abs(n));
		new_denominator = -1 * pow(original_numerator, abs(n));
	}
    else {
        new_numerator = pow(original_numerator, n);
        new_denominator = pow(original_denominator, n);
    }
    Rational x = Rational(new_numerator, new_denominator);
    return x;
}

string to_s(const Rational& r)
{
    Rational t = r;
    string message = t.numerator() + "/" + t.denominator();
    return message;
}