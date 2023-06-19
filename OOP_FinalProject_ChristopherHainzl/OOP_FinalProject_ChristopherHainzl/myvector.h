#include <iostream>
#include <initializer_list>
#include <iterator>
#include <limits>
using namespace std;
template <typename T>
class myvector
{
private:
		T* p;
		unsigned vectorsize;
		unsigned vectorcapacity;
public:
	typedef T* iterator;
	typedef reverse_iterator<T*> rev_iterator;
	typedef const T* constant_iterator;
	typedef reverse_iterator<const T*> constant_rev_iterator;
	/*
		Constructors
	*/
	//default constructor
	myvector();
	//constructor with size
	myvector(unsigned s);
	//constructor with size and value
	myvector(unsigned s, T val);
	//copy constructor
	myvector(const myvector& v);
	//move constructor
	myvector(myvector&& v) noexcept;
	//initializer list constructor
	myvector(initializer_list<T> list);
	// Range constructor
	template<typename InputIterator, typename = typename std::iterator_traits<InputIterator>::difference_type>
	myvector(InputIterator first, InputIterator last) {
		vectorsize = distance(first, last);
		vectorcapacity = vectorsize;
		p = new T[vectorsize];
		int i = 0;
		InputIterator ip = first;
		while (ip != last) {
			p[i] = *ip;
			i++;
			ip++;
		}
	}
	//destructor
	~myvector()
	{
		delete[] p;
	}
	/*
			Element access
	*/

	//Subscript operators
	T& operator[](unsigned pos);
	const T& operator[](unsigned pos) const; //const version

	// Const and nonconst access functions
	iterator begin();
	inline constant_iterator begin() const
	{
		return p;
	}
	constant_iterator cbegin() const;
	iterator end();
	inline constant_iterator end() const
	{
		return p + vectorsize;
	}
	constant_iterator cend() const;
	reverse_iterator<T*> rbegin();
	constant_iterator rbegin() const {
		auto it = make_reverse_iterator(begin());
		return it;
	}
	reverse_iterator<const T*> crbegin() const;
	reverse_iterator<T*> rend();
	reverse_iterator<const T*> rend() const {
		auto it = make_reverse_iterator(begin());
		return it;
	}
	reverse_iterator<const T*> crend() const {
		auto it = make_reverse_iterator(begin());
		return it;
	}
	const T at(unsigned pos) const;
	T at(unsigned pos);
	T* data() { return p; }
	const T* data() const { return p; }

	T& front() { 
		return p[0]; 
	}
	constexpr T& front() const {
		return p[0];
	};
	T& back() { 
		return p[vectorsize - 1]; 
	}
	constexpr T& back() const {
		return p[vectorsize - 1];
	}

	//Size functions
	unsigned length() const { 
		return vectorsize; 
	}
	unsigned size() const { 
		return vectorsize; 
	}
	unsigned capacity() const {
		return vectorcapacity;
	}
	bool empty() const {
		return vectorsize == 0; 
	}
	unsigned max_size() const {
		return std::numeric_limits<signed>::max();
	}
	
	
	// Modifiers
	void push_back(const T& val) {
		if (vectorsize == vectorcapacity)
		{
			if (vectorcapacity == 0)
			{
				vectorcapacity = 1;
			}
			else
			{
				vectorcapacity *= 2;
			}
			T* temp = new T[vectorcapacity];
			for (int i = 0; i < vectorsize; i++)
			{
				temp[i] = p[i];
			}
			delete[] p;
			p = temp;
		}
		p[vectorsize] = val;
		vectorsize++;
	}
	void push_back(T&& val) {
		if (vectorsize == vectorcapacity)
		{
			if (vectorcapacity == 0)
			{
				vectorcapacity = 1;
			}
			else
			{
				vectorcapacity *= 2;
			}
			T* temp = new T[vectorcapacity];
			for (int i = 0; i < vectorsize; i++)
			{
				temp[i] = p[i];
			}
			delete[] p;
			p = temp;
		}
		p[vectorsize] = move(val);
		vectorsize++;
	}
	
	void pop_back();
	// Erase functions using iterators
	iterator erase(iterator pos);
	iterator erase(iterator first, iterator last) {
		T* temp = new T[vectorsize - distance(first, last)];
		int i = 0;
		for (iterator it = begin(); it != first; it++) {
			temp[i] = *it;
			i++;
		}
		for (iterator it = last; it != end(); it++) {
			temp[i] = *it;
			i++;
		}
		delete[] p;
		p = temp;
		vectorsize -= distance(first, last);
		vectorcapacity = vectorsize;
		return first;
	}
	iterator insert(iterator pos, const T& val);
	iterator insert(iterator pos, unsigned n, T val);
	iterator insert(iterator pos, initializer_list<T> list);
	iterator insert(iterator pos, T&& val) {
		T* temp = new T[vectorsize + 1];
		vectorsize++;
		vectorcapacity = vectorsize;
		int i = 0;
		for (iterator it = begin(); it != pos; it++) {
			temp[i] = *it;
			i++;
		}
		temp[i] = move(val);
		i++;
		for (iterator it = pos; it != end(); it++) {
			temp[i] = *it;
			i++;
		}
		delete[] p;
		p = temp;
		return pos;
	}
	template<typename InputIterator, typename = typename std::iterator_traits<InputIterator>::difference_type>
	iterator insert(iterator pos, InputIterator first, InputIterator last) {
		T* temp = new T[vectorsize + distance(first, last)];
		vectorsize += distance(first, last);
		vectorcapacity = vectorsize;
		int i = 0;
		for (iterator it = begin(); it != pos; it++) {
			temp[i] = *it;
			i++;
		}
		for (InputIterator it = first; it != last; it++) {
			temp[i] = *it;
			i++;
		}
		for (iterator it = pos; it != end(); it++) {
			temp[i] = *it;
			i++;
		}
		delete[] p;
		p = temp;
		return pos;
	}

	void assign(unsigned n, T val);

	template<typename InputIterator, typename = typename std::iterator_traits<InputIterator>::difference_type>
	void assign(InputIterator first, InputIterator last) {
        vectorsize = distance(first, last);
		vectorcapacity = vectorsize;
		p = new T[vectorsize];
		int i = 0;
		InputIterator ip = first;
		while (ip != last) {
			p[i] = *ip;
			i++;
			ip++;
		}
	}
	void assign(initializer_list<T> list);
	void swap(myvector& v);
	const void swap(myvector& v) const;

	void resize(unsigned n);
	void resize(unsigned n, T val);

	void reserve(unsigned n);

	void clear();

	void shrink_to_fit();

	// Operator =
	myvector& operator=(const myvector& v);
	myvector& operator=(initializer_list<T> list);
	myvector& operator= (myvector&& v) noexcept;

};

//I/O functions
template <typename T>
ostream& operator<<(ostream& out, const myvector<T>& a);

// Relational operators
template <typename T>
bool operator==(const myvector<T>& a, const myvector<T>& b);

template <typename T>
bool operator!=(const myvector<T>& a, const myvector<T>& b);

template <typename T>
bool operator<(const myvector<T>& a, const myvector<T>& b);

template <typename T>
bool operator<=(const myvector<T>& a, const myvector<T>& b);

template <typename T>
bool operator>(const myvector<T>& a, const myvector<T>& b);

template <typename T>
bool operator>=(const myvector<T>& a, const myvector<T>& b);

// overloaded = operator
template<typename T>
myvector<T>& myvector<T>::operator=(const myvector<T>& v) {
	if (this != &v) {
		delete[] p;
		p = new T[v.vectorsize];
		vectorsize = v.vectorsize;
		vectorcapacity = v.vectorcapacity;
		for (int i = 0; i < vectorsize; i++)
		{
			p[i] = v.p[i];
		}
	}
	return *this;
}

// move assignment operator
template<typename T>
myvector<T>& myvector<T>::operator= (myvector<T>&& v) noexcept {
	if (this != &v) {
		delete[] p;
		p = v.p;
		vectorsize = v.vectorsize;
		vectorcapacity = v.vectorcapacity;
		v.p = nullptr;
		v.vectorsize = 0;
		v.vectorcapacity = 0;
	}
	return *this;
}

// Initializer list assignment operator
template<typename T>
myvector<T>& myvector<T>::operator=(initializer_list<T> list) {
	delete[] p;
	p = new T[list.size()];
	vectorsize = list.size();
	vectorcapacity = vectorsize;
	int i = 0;
	for (auto it = list.begin(); it != list.end(); it++) {
		p[i] = *it;
		i++;
	}
	return *this;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::begin(){
	return p;
}

template<typename T>
typename myvector<T>::constant_iterator myvector<T>::cbegin() const{
	return p;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::end(){
	return p + vectorsize;
}

template<typename T>
typename myvector<T>::constant_iterator myvector<T>::cend() const{
	return p + vectorsize;
}

template<typename T>
typename myvector<T>::rev_iterator myvector<T>::rbegin() {
	auto it = make_reverse_iterator(end());
	return it;
}

template<typename T>
typename myvector<T>::constant_rev_iterator myvector<T>::crbegin() const {
	auto it = make_reverse_iterator(end());
	return it;
}

template<typename T>
typename myvector<T>::rev_iterator myvector<T>::rend() {
	auto it = make_reverse_iterator(begin());
	return it;
}

template<typename T>
myvector<T>::myvector(){
	p = nullptr;
	vectorsize = 0;
	vectorcapacity = 0;
}

template <typename T>
myvector<T>::myvector(unsigned s) {
	p = new T[s];
	T val = T();
	for (int i = 0; i < s; i++)
	{
		p[i] = val;
	}
	vectorsize = s;
	vectorcapacity = s;
}

template <typename T>
myvector<T>::myvector(unsigned s, T val) {
	p = new T[s];
	vectorsize = s;
	vectorcapacity = s;
	for (int i = 0; i < vectorsize; i++)
	{
		p[i] = val;
	}
}

template <typename T>
myvector<T>::myvector(const myvector& v) {
	p = new T[v.vectorsize];
	vectorsize = v.vectorsize;
	vectorcapacity = v.vectorcapacity;
	for (int i = 0; i < vectorsize; i++)
	{
		p[i] = v.p[i];
	}
}

template <typename T>
myvector<T>::myvector(myvector&& v) noexcept {
	p = v.p;
	vectorsize = v.vectorsize;
	vectorcapacity = v.vectorcapacity;
	v.p = nullptr;
	v.vectorsize = 0;
	v.vectorcapacity = 0;
}

template <typename T>
myvector<T>::myvector(initializer_list<T> list) {
	p = new T[list.size()];
	vectorsize = list.size();
	vectorcapacity = list.size();
	int i = 0;
	for (auto it = list.begin(); it != list.end(); it++)
	{
		p[i] = *it;
		i++;
	}
}

template <typename T>
T& myvector<T>::operator[](unsigned pos){
	return p[pos];
}

template <typename T>
const T& myvector<T>::operator[](unsigned pos) const
{
	if (pos >= vectorsize)
	{
		throw out_of_range("Out of range");
	}
	return p[pos];
}

template <typename T>
const T myvector<T>::at(unsigned pos) const
{
	if (pos >= vectorsize)
	{
		throw out_of_range("Out of range");
	}
	return p[pos];
}

template <typename T>
T myvector<T>::at(unsigned pos)
{
	if (pos >= vectorsize)
	{
		throw out_of_range("Out of range");
	}
	return p[pos];
}

template <typename T>
void myvector<T>::resize(unsigned n, T val) {
	if (n > vectorsize)
	{
		if (n > vectorcapacity)
		{
			vectorcapacity = n;
			T* temp = new T[vectorcapacity];
			for (int i = 0; i < vectorsize; i++)
			{
				temp[i] = p[i];
			}
			delete[] p;
			p = temp;
		}
		for (int i = vectorsize; i < n; i++)
		{
			p[i] = val;
		}
		vectorsize = n;
	}
	else if (n < vectorsize)
	{
		vectorsize = n;
	}
}

template <typename T>
void myvector<T>::pop_back() {
	if (vectorsize == 0)
	{
		cerr << "Vector is empty" << endl;
		return;
	}
	vectorsize--;
}

template <typename T>
typename myvector<T>::iterator myvector<T>::erase(iterator pos) {
	if (pos == end())
	{
		cerr << "Out of range" << endl;
		return pos;
	}
	for (iterator it = pos; it != end(); it++)
	{
		*it = *(it + 1);
	}
	vectorsize--;
	return pos;
}

template <typename T>
void myvector<T>::assign(unsigned n, T val) {
	if (n > vectorcapacity)
	{
		delete[] p;
		p = new T[n];
		vectorcapacity = n;
	}
	vectorsize = n;
	for (int i = 0; i < vectorsize; i++)
	{
		p[i] = val;
	}
}

template <typename T>
void myvector<T>::assign(initializer_list<T> list) {
	if (list.size() > vectorcapacity)
	{
		delete[] p;
		p = new T[list.size()];
		vectorcapacity = list.size();
	}
	vectorsize = list.size();
	int i = 0;
	for (auto it = list.begin(); it != list.end(); it++)
	{
		p[i] = *it;
		i++;
	}
}



template<typename T>
typename myvector<T>::iterator myvector<T>::insert(iterator pos, const T& val) {
	if (pos == end())
	{
		throw out_of_range("Out of range");
	}
	T* temp = new T[vectorsize + 1];
	vectorsize++;
	vectorcapacity = vectorsize;
	int i = 0;
	for (auto it = begin(); it != pos; it++) {
		temp[i] = *it;
		i++;
	}
	temp[i] = val;
	i++;
	for (auto it = pos; it != end(); it++) {
		temp[i] = *it;
		i++;
	}
	delete[] p;
	p = temp;
	return pos;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::insert(iterator pos, unsigned n, T val) {
	T* temp = new T[vectorsize + n];
	vectorsize += n;
	vectorcapacity = vectorsize;
	int i = 0;
	for (auto it = begin(); it != pos; it++) {
		temp[i] = p[i];
		i++;
	}
	for (int j = 0; j < n; j++) {
		temp[i] = val;
		i++;
	}
	for (auto it = pos + n; it != end(); it++) {
		temp[i] = p[i - n];
		i++;
	}
	delete[] p;
	p = temp;
	return pos;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::insert(iterator pos, initializer_list<T> list) {
	vectorsize += list.size();
	vectorcapacity = vectorsize;
	T* temp = new T[vectorsize + list.size()];
	int i = 0;
	for (auto it = begin(); it != pos; it++) {
		temp[i] = p[i];
		i++;
	}
	for (auto it = list.begin(); it != list.end(); it++) {
		temp[i] = *it;
		i++;
	}
	for (auto it = pos; it != end(); it++) {
		temp[i] = p[i];
		i++;
	}
	delete[] p;
	p = temp;
	return pos;
}

template <typename T>
void myvector<T>::swap(myvector& v) {
	T* temp = p;
	p = v.p;
	v.p = temp;
	int temp2 = vectorsize;
	vectorsize = v.vectorsize;
	v.vectorsize = temp2;
	temp2 = vectorcapacity;
	vectorcapacity = v.vectorcapacity;
	v.vectorcapacity = temp2;
}

template <typename T>
void swap(myvector<T>& x, myvector<T>& y) {
	x.swap(y);
}

template <typename T>
const void myvector<T>::swap(myvector& v) const {
	T* temp = p;
	p = v.p;
	v.p = temp;
	int temp2 = vectorsize;
	vectorsize = v.vectorsize;
	v.vectorsize = temp2;
	temp2 = vectorcapacity;
	vectorcapacity = v.vectorcapacity;
	v.vectorcapacity = temp2;
}

template <typename T>
void myvector<T>::resize(unsigned n) {
	if (n > vectorsize)
	{
		T* temp = new T[n];
		T val = T();
		int m = 0;
		for (int i = 0; i < vectorsize; i++)
		{
			temp[i] = p[i];
			m++;
		}
		for (int i = m; i < n; i++)
		{
			temp[i] = val;
		}
		delete[] p;
		p = temp;
		vectorsize = n;
		vectorcapacity = n;
	}
	else if (n < vectorsize)
	{
		T* temp = new T[n];
		for (int i = 0; i < n; i++)
		{
			temp[i] = p[i];
		}
		delete[] p;
		p = temp;
		vectorsize = n;
		vectorcapacity = n;
	}
}

template <typename T>
void myvector<T>::clear() {
	vectorsize = 0;
}

template <typename T>
void myvector<T>::reserve(unsigned n) {
	if (n > vectorcapacity)
	{
		T* temp = new T[n];
		for (int i = 0; i < vectorsize; i++)
		{
			temp[i] = p[i];
		}
		delete[] p;
		p = temp;
		vectorcapacity = n;
	}
}

template <typename T>
void myvector<T>::shrink_to_fit() {
	if (vectorsize < vectorcapacity)
	{
		T* temp = new T[vectorsize];
		for (int i = 0; i < vectorsize; i++)
		{
			temp[i] = p[i];
		}
		delete[] p;
		p = temp;
		vectorcapacity = vectorsize;
	}
}