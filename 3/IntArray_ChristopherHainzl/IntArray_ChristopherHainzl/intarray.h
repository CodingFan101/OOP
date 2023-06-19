//The following code would be in a header file
//intarray.h

#include <iostream>
#include <initializer_list>
#include <iterator>
#include <vector>
#include <list>
using namespace std;
class Array_Error {
private:
    string err_msg;
public:
    Array_Error(const string& s) : err_msg(s) {}
    string get_message() { return err_msg; }
};

class IntArray {
private:
    int* p; //pointer to int array data
    unsigned sz; //size of the array
    
public:
    //Constructors
    IntArray(); //Default constructor
    IntArray(unsigned n, int val = 0);
    IntArray(const int* a, unsigned n);
    IntArray(const IntArray& a); //Copy constructor
    // Move constructor
	IntArray(IntArray&& a) noexcept {
        p = a.p;
		sz = a.sz;
		a.p = nullptr;
		a.sz = 0;
    }
    
    // Move assignment operator
    IntArray& operator= (IntArray&& a) noexcept;
    
    // Initializer list constructor
	IntArray(initializer_list<int> list) : p(new int[list.size()]), sz(list.size()) {
		int i = 0;
		for (auto it = list.begin(); it != list.end(); it++) {
			p[i] = *it;
			i++;
		}
	}
    
    // Range constructor
    template<typename InputIterator, typename = typename std::iterator_traits<InputIterator>::difference_type>
    IntArray(InputIterator first, InputIterator last) {
        sz = distance(first, last);
        p = new int[sz];
        int i = 0;
		InputIterator ip = first;
		while (ip != last) {
			p[i] = *ip;
            i++;
			ip++;
		}
    }

    //Destructor
    ~IntArray();

    //Assignment operators
    IntArray& operator=(const IntArray& a);

    //Subscript operators
    int& operator[](unsigned pos);
    const int& operator[](unsigned pos) const; //const version

    //Size functions
    unsigned length() const { return sz; }
    unsigned size() const { return sz; }
    bool empty() const { return sz == 0; }
    void resize(unsigned n, int val = 0);

    // Const access functions
    const int at(unsigned pos) const {
        if (pos >= sz || pos < 0) { 
            throw Array_Error("Index out of bounds"); 
        }
        else {
            return p[pos];
        }
    };
	const int front() const { return p[0]; };
	const int back() const { return p[sz - 1]; };
    
    // Nonconst access functions
	int at(unsigned pos) {
        if (pos >= sz || pos < 0) {
            throw Array_Error("Index out of bounds");
        }
        else {
            return p[pos];
        }
    };
	int front() { return p[0]; };
	int back() { return p[sz - 1]; };
    
    // Insert and delete member functions
	void insert(unsigned pos, int x);
	void insert(unsigned pos, unsigned n, int x);
    void push_back(int x);
    void pop_back();
    void erase(unsigned pos);
	void erase(unsigned first, unsigned last);
    void clear();

    unsigned capacity();
	void reserve(unsigned n);
    void shrink_to_fit();
    void swap(IntArray& a);

	// Iterator functions for demonstrating that STL algorithms work
	int* begin() { return p; };
	int* end() { return p + sz; };
	const int* begin() const { return p; };
    const int* end() const { return p + sz; }
};

//I/O functions
ostream& operator<<(ostream& out, const IntArray& a);
istream& operator>>(istream& in, IntArray& a);

//Relational operators
bool operator==(const IntArray& a1, const IntArray& a2);
bool operator!=(const IntArray& a1, const IntArray& a2);
bool operator<(const IntArray& a1, const IntArray& a2);
bool operator<=(const IntArray& a1, const IntArray& a2);
bool operator>(const IntArray& a1, const IntArray& a2);
bool operator>=(const IntArray& a1, const IntArray& a2);




//Inline member functions of IntArray

//Default constructor, creates array of size 0
IntArray::IntArray() : p(0), sz(0) {}

//Creates array of n elements all initialized to val
IntArray::IntArray(unsigned n, int val) : p(new int[n]), sz(n)
{
    for (unsigned i = 0; i < n; i++)
        p[i] = val;
}

//Creates a copy of integer array a
IntArray::IntArray(const int* a, unsigned n) : p(new int[n]), sz(n)
{
    for (unsigned i = 0; i < n; i++)
        p[i] = a[i];
}

//Creates a copy of IntArray a
IntArray::IntArray(const IntArray& a) : p(new int[a.sz]), sz(a.sz)
{
    for (unsigned i = 0; i < sz; i++)
        p[i] = a.p[i];
}

//Destructor
IntArray::~IntArray()
{
    delete[] p;
}

//Subscript operators

//The following works for const arrays
const int& IntArray::operator[](unsigned pos) const
{
    if (pos >= sz)
        throw(Array_Error("Out of range"));
    return(p[pos]);
}

//The following works for non-const arrays
int& IntArray::operator[](unsigned pos)
{
    return const_cast<int&>(static_cast<const IntArray&>(*this)[pos]);
}