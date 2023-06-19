class A {
public:
	A() { val = 0; }
	virtual ~A() {}
protected:
	A(int x) { val = x; }
private:
	int val;
};
class B : public A {
public:
	B() : A(0) {}
	A* createA(int x = 0) { return new A(x); }
};