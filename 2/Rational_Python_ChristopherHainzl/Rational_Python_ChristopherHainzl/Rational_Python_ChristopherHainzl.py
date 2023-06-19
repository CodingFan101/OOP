class Rational:
    def __init__(self, num, denom):
        self.num = num
        self.denom = denom
        # make sure that denom is not equal to 0, if so, throw an error
        if self.denom == 0:
            raise ZeroDivisionError("Denominator cannot be zero")
        self.simplify()
    @property
    def num(self):
        return self._num
    @num.setter
    def num(self, num):
        self._num = num
    @property
    def denom(self):
        return self._denom
    @denom.setter
    def denom(self, denom):
        self._denom = denom
    def __str__(self):
        return str(self.num) + "/" + str(self.denom)
    def __add__(self, other):
        return Rational(self.num * other.denom + self.denom * other.num, self.denom * other.denom)
    def __sub__(self, other):
        return Rational(self.num * other.denom - self.denom * other.num, self.denom * other.denom)
    def __mul__(self, other):
        return Rational(self.num * other.num, self.denom * other.denom)
    def __floordiv__(self, other):
        return Rational(self.num * other.denom, self.denom * other.num)
    def __lt__(self, other):
        return self.num * other.denom < self.denom * other.num
    def simplify(self):
        gcd = self.gcd(self.num, self.denom)
        self.num = self.num // gcd
        self.denom = self.denom // gcd
    def gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return a
    
# test the class
r1 = Rational(1, 2)
r2 = Rational(-1, 3)
r3 = Rational(4, 6)
r4 = Rational(3, 5)
print("R1: ", r1)
print("R2: ", r2)
print("R3: ", r3)
print("R4: ", r4)
print("Numerator of R4: ", r4.num)
print("Denominator of R4: ", r4.denom)
print("R1 + R2: ", r1 + r2)
print("R1 - R2: ", r1 - r2)
print("R1 * R2: ", r1 * r2)
print("R1 / R2: ", r1 // r2)
print("R1 * R3: ", r1 * r3)
print("Truth value of R1 < R2: ", r1 < r2)
print("Truth value of R1 < R3: ", r1 < r3)