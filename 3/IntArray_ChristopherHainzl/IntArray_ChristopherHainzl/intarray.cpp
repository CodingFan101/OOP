#include <iomanip> //For output formatting
#include <utility>
#include <algorithm>
#include "intarray.h"
//Assignment operators
IntArray& IntArray::operator=(const IntArray& a)
{
    if (&a != this) { //Avoids self-assignment
        delete[] p;
        p = new int[a.sz];
        sz = a.sz;
        for (unsigned i = 0; i < sz; i++)
            p[i] = a.p[i];
    }
    return *this;
}

bool operator<(const IntArray& a1, const IntArray& a2) {
	// compare the arrays using dictionary order
	bool less = false;
	if (a1.size() < a2.size()) {
		less = true;
		return less;
	}
	unsigned n = a1.size();
	for (int i = 0; i < n; i++) {
		if (a1[i] < a2[i]) {
			less = true;
			return less;
		}
		else {
			less = false;
		}
	}
	return less;
}

bool operator<=(const IntArray& a1, const IntArray& a2) {
	bool less = false;
	if (a1.size() < a2.size()){
		less = true;
		return less;
	}
	unsigned n = a1.size();
	for (int i = 0; i < n; i++) {
		if (a1[i] <= a2[i]) {
			less = true;
			return less;
		}
		else {
			less = false;
		}
	}
	return less;
}

bool operator>(const IntArray& a1, const IntArray& a2) {
	bool greater = false;
	if (a1.size() > a2.size()){
		greater = true;
		return greater;
	}
	unsigned n = a1.size();
	for (int i = 0; i < n; i++) {
		if (a1[i] > a2[i]) {
			greater = true;
			return greater;
		}
		else {
			greater = false;
		}
	}
		return greater;
}

bool operator>=(const IntArray& a1, const IntArray& a2) {
	bool greater = false;
	if (a1.size() > a2.size()){
		greater = true;
		return greater;
	}
	unsigned n = a1.size();
	for (int i = 0; i < n; i++) {
		if (a1[i] >= a2[i]) {
			greater = true;
			return greater;
		}
		else {
			greater = false;
		}
	}
	return greater;
}

//Resize array, initialize new elements to val
void IntArray::resize(unsigned n, int val)
{
    int* temp = new int[n];
    unsigned i;

    if (n > sz) { //Array is increasing in size
        for (i = 0; i < sz; i++) temp[i] = p[i];
        for (; i < n; i++) temp[i] = val;
    }
    else { //Array is decreasing in size
        for (i = 0; i < n; i++) temp[i] = p[i];
    }
    delete[] p;
    p = temp;
    sz = n;
}

//I/O functions
ostream& operator<<(ostream& out, const IntArray& a)
{
    unsigned n = a.size();

    for (unsigned i = 0; i < n; i++)
        out << a[i] << "  ";
    return out;
}

istream& operator>>(istream& in, IntArray& a)
{
    unsigned n = a.size();

    for (unsigned i = 0; i < n; i++)
        in >> a[i];
    return in;
}

//Relational operators
bool operator==(const IntArray& a1, const IntArray& a2)
{
    bool equal = false;

    if (a1.size() == a2.size()) {
        unsigned n = a1.size();
        unsigned i;

        for (i = 0; i < n && a1[i] == a2[i]; i++)
            ;
        if (i == n)
            equal = true;
    }
    return equal;
}

bool operator!=(const IntArray& a1, const IntArray& a2)
{
    return !(a1 == a2);
}

// Move assignment operator
IntArray& IntArray::operator=(IntArray&& a) noexcept {
	if (this != &a) {
		delete[] p;
		p = a.p;
		sz = a.sz;
		a.p = nullptr;
		a.sz = 0;
	}
	return *this;
}

void IntArray::insert(unsigned pos, int x) {
	if (pos >= sz || pos < 0) {
		throw Array_Error("Index out of bounds");
	}
	else {
		int* temp = new int[sz + 1];
		for (unsigned i = 0; i < pos; i++) {
			temp[i] = p[i];
		}
		temp[pos] = x;
		for (unsigned i = pos; i < sz; i++) {
			temp[i + 1] = p[i];
		}
		delete[] p;
		p = temp;
		sz++;
	}

}

void IntArray::insert(unsigned pos, unsigned n, int x) {
	if (pos >= sz || pos < 0) {
		throw Array_Error("Index out of bounds");
	}
	else {
		int* temp = new int[sz + n];
		for (unsigned i = 0; i < pos; i++) {
			temp[i] = p[i];
		}
		for (unsigned i = pos; i < pos + n; i++) {
			temp[i] = x;
		}
		for (unsigned i = pos; i < sz; i++) {
			temp[i + n] = p[i];
		}
		delete[] p;
		p = temp;
		sz += n;
	}
}

void IntArray::push_back(int x) {
	int* temp = new int[sz + 1];
	for (unsigned i = 0; i < sz; i++) {
		temp[i] = p[i];
	}
	temp[sz] = x;
	delete[] p;
	p = temp;
	sz++;
}

void IntArray::pop_back() {
	if (sz == 0) {
		throw Array_Error("Array is empty");
	}
	else {
		int* temp = new int[sz - 1];
		for (unsigned i = 0; i < sz - 1; i++) {
			temp[i] = p[i];
		}
		delete[] p;
		p = temp;
		sz--;
	}
}

void IntArray::erase(unsigned pos){
	if (pos >= sz || pos < 0){
		throw Array_Error("Index out of bounds");
	}
	else {
		int* temp = new int[sz - 1];
		for (unsigned i = 0; i < pos; i++) {
			temp[i] = p[i];
		}
		for (unsigned i = pos; i < sz - 1; i++) {
			temp[i] = p[i + 1];
		}
		delete[] p;
		p = temp;
		sz--;
	} 
}

void IntArray::erase(unsigned first, unsigned last){
	if ((first >= sz || last >= sz) || (first < 0 || last < 0)) {
		throw Array_Error("Index out of bounds");
	}
	else {
		int* temp = new int[sz - (last - first)];
		for (unsigned i = 0; i <= first; i++) {
			temp[i] = p[i];
		}
		for (unsigned i = first; i <= sz - (last - first); i++) {
			temp[i] = p[i + (last - first)];
		}
		delete[] p;
		p = temp;
		sz -= (last - first);
	}
}

void IntArray::clear() {
	if (sz == 0) {
		throw Array_Error("Array is empty");
	}
	else {
		delete[] p;
		p = nullptr;
	}
}

unsigned IntArray::capacity() {
	return sz;
}

void IntArray::reserve(unsigned n) {
	if (n > sz) {
		int* temp = new int[n];
		for (unsigned i = 0; i < sz; i++) {
			temp[i] = p[i];
		}
		delete[] p;
		p = temp;
		sz = n;
	}
}

void IntArray::shrink_to_fit() {
	if (sz != 0) {
		int* temp = new int[sz];
		for (unsigned i = 0; i < sz; i++) {
			temp[i] = p[i];
		}
		delete[] p;
		p = temp;
	}
}

void IntArray::swap(IntArray& a) {
	for (unsigned i = 0; i < sz; i++) {
		int temp = p[i];
		p[i] = a[i];
		a[i] = temp;
	}
}

int main() {
	IntArray a(10, 5);

	cout << "a.size() = " << a.size() << endl;
	cout << a << endl;

	IntArray b;
	b.resize(10);
	for (int i = 0; i < b.size(); i++)
		b[i] = i * i;

	cout << "b.size() = " << b.size() << endl;
	cout << b << endl;

	try {
		cout << a[12];
	}
	catch (Array_Error e) {
		cout << e.get_message() << endl;
	}

	IntArray c(b); //Copy ctor
	cout << "c.size() = " << c.size() << endl;
	cout << c << endl;

	if (c != b)
		cout << "IntArrays b,c not equal\n";
	else
		cout << "IntArrays b,c are equal\n";

	// Initializer list constructor
	IntArray d{ 3, 4, 5, 6, 7 };
	cout << "d.size() = " << d.size() << endl;
	d.erase(2);
	cout << "d.size() after removing number at index 2 = " << d.size() << endl;
	cout << "d after removing number at index 2: " << d << endl;
	cout << endl;

	d.erase(1, 3);
	cout << "d.size() after removing numbers at index 1, inclusive, to 3, not inclusive = " << d.size() << endl;
	cout << "d after removing numbers at index 1, inclusive, to 3, not inclusive: " << d << endl;
	cout << endl;

	// Clear the screen and press enter to continue
	system("pause");
	system("cls");
	
	
	// Access functions
	cout << d << endl;
	cout << "d.front() = " << d.front() << endl;
	cout << "d.back() = " << d.back() << endl;
	cout << "Element at index 1 in d = " << d.at(1) << endl;
	cout << endl;
	IntArray e{ 8,3,5,2,6 };
	IntArray f{ 8,3,5,3,4 };

	// Overloaded operators
	bool less = e < f;
	bool lessorequal = e <= f;
	bool greater = f > e;
	bool greaterorequal = f >= e;
	cout << "Is e less than f? " << boolalpha << less << endl;
	cout << "Is e less than or equal to f? " << boolalpha << lessorequal << endl;
	cout << "Is f greater than e? " << boolalpha << greater << endl;
	cout << "Is f greater than or equal to e? " << boolalpha << greaterorequal << endl;

	// Clear the screen and press enter to continue
	system("pause");
	system("cls");

	// Push_back, pop_back, swap, and clear functions
	f.push_back(7);
	cout << "Contents of f after push_back: " << f << endl;
	f.pop_back();
	cout << "Contents of f after pop_back: " << f << endl;
	cout << "Contents of e before swapping with a: " << e << endl;
	e.swap(a);
	cout << "Contents of e after swapping with a: " << e << endl;
	cout << "Contents of a after swapping with e: " << a << endl;
	e.clear();
	cout << "Capacity of e: " << e.capacity() << endl;
	
	cout << "Contents of f before inserting anything: " << f << endl;
	
	f.insert(0, 2, 6);
	cout << "Contents of f after inserting 2 6's at index 0: " << f << endl;

	f.insert(1, 9);
	cout << "Contents of f after inserting 9 at index 1: " << f << endl;
	cout << "New capacity of f: " << f.capacity() << endl;

	// Clear the screen and press enter to continue
	system("pause");
	system("cls");
	
	// Range constructor
	vector<int> g{ 1, 2, 3, 4, 5 };
	list<int> h{ 6, 7, 8, 9, 10 };
	IntArray g1(g.begin(), g.end());
	IntArray h1(h.begin(), h.end());
	cout << "Contents of g1: " << g1 << endl;
	cout << "Contents of h1: " << h1 << endl;
	g1.reserve(10);
	cout << "Contents of g1 after reserving 10 elements: " << g1 << endl;
	cout << "Capacity of g1: " << g1.capacity() << endl;
	g1.resize(5);
	g1.shrink_to_fit();
	cout << "Contents of g1 after shrinking to fit: " << g1 << endl;
	cout << "Capacity of g1: " << g1.capacity() << endl;
	
	// Move constructor and move assignment operator
	vector<int> v{ 1,5,3,7,4,8 };
	IntArray x1(v.begin(), v.end());
	IntArray x2(x1);
	IntArray x3{ 1,7,9,8,4,6,3 };
	IntArray x4 = move(x3);
	cout << "Contents of x1 after move assignment operator: " << x1 << endl;
	cout << "Contents of x2 after move assignment operator: " << x2 << endl;
	cout << "Contents of x3 after move assignment operator: " << x3 << endl;
	cout << "Contents of x4 after move assignment operator: " << x4 << endl;
	
	cout << endl;
	
	x3 = x4 = x2;
	x1 = move(x4);
	cout << "Contents of x1 after move assignment operator: " << x1 << endl;
	cout << "Contents of x2 after move assignment operator: " << x2 << endl;
	cout << "Contents of x3 after move assignment operator: " << x3 << endl;
	cout << "Contents of x4 after move assignment operator: " << x4 << endl;

	// Clear the screen and press enter to continue
	system("pause");
	system("cls");

	IntArray sorttest{ 5, 4, 3, 2, 1 };
	sort(sorttest.begin(), sorttest.end());
	cout << "Contents of sorttest after sorting: " << sorttest << endl;

	IntArray copytest{ 1, 2, 3, 4 };
	IntArray copytest2{};
	copytest2.reserve(4);
	copy(copytest.begin(), copytest.end(), copytest2.begin());
	cout << "Contents of copytest2 after copying: " << copytest2 << endl;
	
	IntArray reversecopytest{ 1, 3, 5, 7 };
	IntArray reversecopytest2{};
	reversecopytest2.reserve(4);
	reverse_copy(reversecopytest.begin(), reversecopytest.end(), reversecopytest2.begin());
	cout << "Contents of reversecopytest2 after reverse copying: " << reversecopytest2 << endl;

	IntArray copybackwardtest{ 2, 4, 6, 8 };
	IntArray copybackwardtest2{};
	copybackwardtest2.reserve(4);
	copy_backward(copybackwardtest.begin(), copybackwardtest.end(), copybackwardtest2.end());
	cout << "Contents of copybackwardtest2 after copying backwards: " << copybackwardtest2 << endl;
	return 0;
}