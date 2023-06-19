// Christopher Hainzl
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Rational.h"
using namespace std;
int main() {
	try {
		Rational r1 = Rational(-1, 2);
		Rational r2 = Rational(-1, 3);
		Rational r3 = Rational(5, 2);
		Rational r4 = Rational(7, 4);
		Rational r5 = RationalPower(r1, 3);
		Rational r6 = Rational(0, 6);
		Rational r7 = RationalPower(r4, -3);
		cout << r1 << endl;
		cout << "3^" << r1 << " = " << Power(3, r1) << endl;
		cout << "-3^" << r2 << " = " << Power(-3, r2) << endl;
		cout << "0^" << r4 << " = " << Power(0, r4) << endl;
		cout << "2^" << r6 << " = " << Power(2, r6) << endl;
		cout << "Floor of " << r2 << " = " << floor(r2) << endl;
		cout << "Ceiling of " << r4 << " = " << ceil(r4) << endl;
		cout << r4 << " rounded up is equal to: " << round(r4) << endl;
		cout << "R5: " << r5 << endl;
		cout << "R7: " << r7 << endl;
		return 0;
	}
	catch (Rational_Error& e) {
		cout << e.get_message() << endl;
		return 0;
	}
}