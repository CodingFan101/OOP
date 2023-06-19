#include <iostream>
using namespace std;
struct Base {
	Base() { cout << "A Base is born\n"; }
	virtual ~Base() { cout << "A Base dies\n"; }
	virtual void func() { cout << "Base::func()\n"; }
	virtual void vfunc() { cout << "Base::vfunc()\n"; }
};
struct Der : public Base {
	Der() { cout << "A Der is born\n"; }
	~Der() { cout << "A Der dies\n"; }
	void func() { cout << "Der::func()\n"; }
	virtual void vfunc() { cout << "Der::vfunc()\n"; }
};

int main() {
	Base* bp;
	bp = new Der;
	bp->func();
	bp->vfunc();
	delete bp;
}