#include <iostream>
using namespace std;
class A {
public:
	void f() { cout << "A::f()\n"; }
	virtual void h() { cout << "A::h()\n"; }
};
class B : public virtual A {
public:
	void f() { cout << "B::f()\n"; }
};
class C : public B {
public:
	void g() { cout << "C::g()\n"; }
	void h() { cout << "C::h()\n"; }
};
class D : public C, public virtual A {
public:
	void g() { cout << "D::g()\n"; } 
	void h() { cout << "D::h()\n"; }
};
int main() {
	A* pa = new D; 
	pa->f(); 
	pa->h();
	B* pb = new B; 
	pb->f(); 
	pb->h();
	C* pc = new C; 
	pc->f(); 
	pc->h();
	D* pd = new D; 
	pd->f(); 
	pd->g(); 
	pd->h();
	return 0;
}