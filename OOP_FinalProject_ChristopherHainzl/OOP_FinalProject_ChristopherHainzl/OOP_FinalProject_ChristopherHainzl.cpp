// OOP_FinalProject_ChristopherHainzl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "myvector.h"

//I/O functions
template <typename T>
ostream& operator<<(ostream& out, const myvector<T>& a)
{
    unsigned size = a.length();

    for (unsigned i = 0; i < size; i++)
        out << a[i];
    return out;
}

// Relational operators
template <typename T>
bool operator==(const myvector<T>& a, const myvector<T>& b)
{
	unsigned size = a.length();
	if (size != b.length())
		return false;
	for (unsigned i = 0; i < size; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

template <typename T>
bool operator!=(const myvector<T>& a, const myvector<T>& b)
{
	return !(a == b);
}

template <typename T>
bool operator<(const myvector<T>& a, const myvector<T>& b)
{
	bool less = false;
	if (a.size() < b.size()) {
		less = true;
		return less;
	}
	unsigned n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			less = true;
			return less;
		}
		else {
			less = false;
		}
	}
	return less;
}

template <typename T>
bool operator<=(const myvector<T>& a, const myvector<T>& b)
{
	bool less = false;
	if (a.size() < b.size()) {
		less = true;
		return less;
	}
	unsigned n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] <= b[i]) {
			less = true;
			return less;
		}
		else {
			less = false;
		}
	}
	return less;
}

template <typename T>
bool operator>(const myvector<T>& a, const myvector<T>& b)
{
	bool greater = false;
	if (a.size() > b.size()) {
		greater = true;
		return greater;
	}
	unsigned n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			greater = true;
			return greater;
		}
		else {
			greater = false;
		}
	}
	return greater;
}

template <typename T>
bool operator>=(const myvector<T>& a, const myvector<T>& b)
{
	bool greater = false;
	if (a.size() > b.size()) {
		greater = true;
		return greater;
	}
	unsigned n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] >= b[i]) {
			greater = true;
			return greater;
		}
		else {
			greater = false;
		}
	}
	return greater;
}

template <typename T, typename U>
void erase_if(myvector<T>& a, U pred)
{
	unsigned size = a.length();
	for (unsigned i = 0; i < size; i++) {
		auto temp = a.begin() + i;
		if (pred(a[i]))
			a.erase(temp);
	}
}

template <typename T, typename U>
void erase(myvector<T>& a, const U& value) {
	unsigned size = a.length();
	for (unsigned i = 0; i < size; i++) {
		auto temp = a.begin() + i;
		if (a[i] == value)
			a.erase(temp);
	}
}

int main()
{
	/*
		Initializer list constructor, push_back(), pop_back() functions
		Works in: Visual Studio
	*/
	// Initializer list constructor
	cout << "Testing initializer list constructor, push_back(), pop_back() functions" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout <<"As well as capacity(), size(), front(), back(), and empty() functions" << endl;
    myvector<string> v1{ "Hello", "World"};
	v1.push_back("It's-a me, Mario!");
	cout << "Capacity of v1 is: " << v1.capacity() << endl;
	cout << "Size of v1 is: " << v1.size() << endl;
    for (int i = 0; i < v1.size(); i++)
    {
		cout << v1[i] << endl;
	}
	v1.pop_back();
	cout << "Capacity of v1 is now: " << v1.capacity() << endl;
	cout << "Size of v1 is now: " << v1.size() << endl;

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}

	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");
	
	/*
		front(), back(), and empty() functions
		Works in: Visual Studio
	*/
    myvector<int> v2{ 1, 2, 3, 4, 5 };
	cout << "Element at front of v2 is: " << v2.front() << endl;
	cout << "Element at back of v2 is: " << v2.back() << endl;
	int v2index = 0;
	while (!(v2.empty())) {
		cout << "Element at index " << v2index << " in v2 is: " << v2[v2index] << endl;
		v2index++;
		v2.pop_back();
	}

	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Testing the data() function
		Works in: Visual Studio
	*/
	cout << "Now testing the data() function" << endl;
    myvector<double>v3{ 2.3, 4.5, 6.7 };
    double* p = v3.data();
	cout << "Elements in v3:" << endl;
    for (int i = 0; i < v3.size(); i++)
    {
		cout << p[i] << endl;
	}

	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Testing the range constructor, begin(), and end() functions, as well as the first erase function
		Works in: Visual Studio
	*/
	// Range constructor
	myvector<int> rangetest(v3.begin(), v3.end());
	cout << "Elements in rangetest:" << endl;
	for (int i = 0; i < rangetest.size(); i++)
	{
		cout << rangetest[i] << endl;
	}

	myvector<int>v4{ 2, 4, 6 };
	cout << "Elements in v4:" << endl;
	for (auto it = v4.begin(); it != v4.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements in v5" << endl;
	myvector<int>v5{ 3, 5, 6 };
	for (auto it = v5.begin(); it != v5.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "Testing first erase function" << endl;
	// Erase element at index 1 in v5
	v5.erase(v5.begin() + 1);
	cout << "v5 is now: " << endl;
	for (int i = 0; i < v5.size(); i++)
	{
		cout << v5[i] << endl;
	}

	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Testing the overloaded operators
		Works in: Visual Studio
	*/
	cout << "Now testing overloaded operators" << endl;
	// Overloaded operators
	bool less = v4 < v5;
	bool lessorequal = v4 <= v5;
	bool greater = v5 > v4;
	bool greaterorequal = v5 >= v4;
	bool notequal = v5 != v4;
	cout << "Is v4 less than v5? " << boolalpha << less << endl;
	cout << "Is v4 less than or equal to v5? " << boolalpha << lessorequal << endl;
	cout << "Is v5 greater than v4? " << boolalpha << greater << endl;
	cout << "Is v5 greater than or equal to v4? " << boolalpha << greaterorequal << endl;
	cout << "Is v5 not equal to v4? " << boolalpha << notequal << endl;

	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Testing the assignment operator, second assign function, and copy, size, size & value constructors
		Works in: Visual Studio
	*/
	cout << "Now testing assignment operator, assign functions, and constructors" << endl;
	// Assignment operator
	v4 = v5;
	cout << "v4 is now: " << endl;
	for (int i = 0; i < v4.size(); i++) {
		cout << v4[i] << endl;
	}
	cout << "Element at index 1 in v4 is: " << v4.at(1) << endl;

	// Constructor with size
	myvector<double>v6(8);
	v6.assign(7, 3.14);
	for (int i = 0; i < v6.size(); i++)
	{
		cout << v6[i] << endl;
	}

	// Copy constructor
	myvector<double>v7(v6);
	cout << "Elements of v7: " << endl;
	for (int i = 0; i < v7.size(); i++)
	{
		cout << v7[i] << endl;
	}

	// Constructor with size and value
	myvector<int>v8(5, 10);
	cout << "Elements of v8: " << endl;
	for (int i = 0; i < v8.size(); i++)
	{
		cout << v8[i] << endl;
	}

	myvector<int>v9;
	v9.assign(6, 5);
	cout << "Elements of v9: " << endl;
	for (int i = 0; i < v9.size(); i++)
	{
		cout << v9[i] << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");


	/*
		Testing the third erase function, the insert function, and the reverse iterators
		Works in: Visual Studio
	*/
	cout << "Now testing reverse iterators and max_size() function" << endl;
	myvector<int>v10{ 1, 2, 3, 4, 5 };
	cout << "Elements of v10 are: " << endl;
	for (auto it = v10.begin(); it != v10.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of v10 in reverse order are: " << endl;
	for (auto it = v10.rbegin(); it != v10.rend(); it++)
	{
		cout << *it << endl;
	}
	v10.erase(v10.begin() + 1, v10.begin() + 3);
	cout << "Elements of v10 after erasing elements at index 1 and 2 are: " << endl;
	for (auto it = v10.begin(); it != v10.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Now testing the const iterators, and the max_size() function
		Works in: Visual Studio
	*/
	myvector<int>v11{6, 7, 8, 9, 10};
	cout << "Elements of v11 in reverse order are: " << endl;
	for (auto it = v11.crbegin(); it != v11.crend(); it++)
	{
		cout << *it << endl;
	}
	cout << "Maximum size of v11 is: " << v11.max_size() << endl;
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	cout << "Now testing cbegin, cend, and == operator" << endl;
	myvector<string>v12 = {"Mario"};
	v12.push_back("Luigi");
	v12.push_back("Peach");
	v12.push_back("Toad");
	v12.push_back("Bowser");
	cout << "Elements of v12 are: " << endl;
	for (auto it = v12.cbegin(); it != v12.cend(); it++)
	{
		cout << *it << endl;
	}
	myvector<int>v13{ 1, 2, 3, 4, 5 };
	myvector<int>v14{1, 2, 3, 4, 5};
	myvector<int>v15{10, 11, 12, 13, 14, 15};
	if (v13 == v14) {
		cout << "v13 and v14 are equal" << endl;
	}
	else {
		cout << "v13 and v14 are not equal" << endl;
	}
	if (v13 == v15) {
		cout << "v13 and v15 are equal" << endl;
	}
	else {
		cout << "v13 and v15 are not equal" << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Now testing the swap, resize, and clear functions
		Works in: Visual Studio
	*/
	cout << "Now testing swap and resize functions" << endl;
	myvector<double>v16{1, 2, 3, 4, 5, 11};
	myvector<double>v17{6, 7, 8, 9, 10};
	cout << "Elements of v16 before swap are: " << endl;
	for (auto it = v16.begin(); it != v16.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of v17 before swap are: " << endl;
	for (auto it = v17.begin(); it != v17.end(); it++)
	{
		cout << *it << endl;
	}
	v16.swap(v17);
	cout << "Elements of v16 after swap are: " << endl;
	for (auto it = v16.begin(); it != v16.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of v17 after swap are: " << endl;
	for (auto it = v17.begin(); it != v17.end(); it++)
	{
		cout << *it << endl;
	}

	v17.resize(10);
	cout << "Elements of v17 after resize are: " << endl;
	for (auto it = v17.begin(); it != v17.end(); it++)
	{
		cout << *it << endl;
	}

	v16.resize(11, 3.14);
	cout << "Elements of v16 after resize are: " << endl;
	for (auto it = v16.begin(); it != v16.end(); it++)
	{
		cout << *it << endl;
	}

	v17.clear();
	cout << "Size of v17 after clear is: " << v17.size() << endl;
	cout << "Capacity of v17 after clear is: " << v17.capacity() << endl;
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Now testing the assign functions
		Works in: Visual Studio
	*/
	cout << "Now testing assign functions" << endl;
	// Assign function tests
	myvector<char>v18;
	v18.assign(6, 'z');
	cout << "Elements of v18 are: " << endl;
	for (auto it = v18.begin(); it != v18.end(); it++)
	{
		cout << *it << endl;
	}
	v18.assign({ 'a', 'b', 'c', 'd', 'e', 'f' });
	cout << "Elements of v18 after initializer list assign are: " << endl;
	for (auto it = v18.begin(); it != v18.end(); it++)
	{
		cout << *it << endl;
	}
	myvector<char>v19 = { 'w', 'x', 'y', 'z'};
	v18.assign(v19.begin(), v19.end());
	cout << "Elements of v18 after assign with iterators are: " << endl;
	for (auto it = v18.begin(); it != v18.end(); it++)
	{
		cout << *it << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");
	
	/*
		Now testiing the move constructor and move assignment operator
		Works in: Visual Studio
	*/
	cout << "Now testing move constructor and move assignment operator" << endl;
	// Move constructor and move assignment operator tests
	myvector<int> movetest1 = { 1, 2, 3, 4, 5 };
	myvector<int> movetest2 = { 6, 7, 8, 9, 10 };
	myvector<int> movetest3 = move(movetest2);
	myvector<int> movetest4 = { 11, 12, 13, 14, 15 };

	cout << "Elements of movetest1 are: " << endl;
	for (auto it = movetest1.begin(); it != movetest1.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of movetest2 are: " << endl;
	for (auto it = movetest2.begin(); it != movetest2.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of movetest3 are: " << endl;
	for (auto it = movetest3.begin(); it != movetest3.end(); it++)
	{
		cout << *it << endl;
	}

	movetest1 = movetest3 = movetest4;
	movetest2 = move(movetest3);
	cout << "Elements of movetest1 after assignment are: " << endl;
	for (auto it = movetest1.begin(); it != movetest1.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of movetest3 after assignment are: " << endl;
	for (auto it = movetest3.begin(); it != movetest3.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of movetest4 after assignment are: " << endl;
	for (auto it = movetest4.begin(); it != movetest4.end(); it++)
	{
		cout << *it << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Now testing the erase functions
		Works in: Visual Studio
	*/
	cout << "Now testing erase functions" << endl;
	myvector<int>eraserangetest = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Elements of eraserangetest before erase are: " << endl;
	for (auto it = eraserangetest.begin(); it != eraserangetest.end(); it++)
	{
		cout << *it << endl;
	}
	eraserangetest.erase(eraserangetest.begin());
	cout << "Elements of eraserangetest after erasing 0 are: " << endl;
	for (auto it = eraserangetest.begin(); it != eraserangetest.end(); it++)
	{
		cout << *it << endl;
	}
	eraserangetest.erase(eraserangetest.begin() + 2, eraserangetest.begin() + 5);
	cout << "Elements of eraserangetest are now: " << endl;
	for (auto it = eraserangetest.begin(); it != eraserangetest.end(); it++)
	{
		cout << *it << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Now testing the shrink_to_fit and reserve functions
		Works in: Visual Studio
	*/
	cout << "Now testing shrink_to_fit and reserve functions" << endl;
	myvector<int>shrinktest(100);
	cout << "Capacity of shrinktest before shrink_to_fit is: " << shrinktest.capacity() << endl;
	cout << "Size of shrinktest before shrink_to_fit is: " << shrinktest.size() << endl;
	shrinktest.resize(10);
	shrinktest.shrink_to_fit();
	cout << "Capacity of shrinktest after resizing to 10 and shrink_to_fit is: " << shrinktest.capacity() << endl;
	cout << "Size of shrinktest after resizing to 10 and shrink_to_fit is: " << shrinktest.size() << endl;
	shrinktest.reserve(15);
	cout << "Capacity of shrinktest after reserve(15) is: " << shrinktest.capacity() << endl;
	cout << "Size of shrinktest after reserve(15) is: " << shrinktest.size() << endl;
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Now testing the non-member erase function and erase_if function
		Works in: Visual Studio
	*/
	cout << "Now testing non-member erase function and erase_if function" << endl;
	myvector<int> erasetest{20, 30, 40, 50, 60};
	cout << "Elements of erasetest before erase are: " << endl;
	for (auto it = erasetest.begin(); it != erasetest.end(); it++)
	{
		cout << *it << endl;
	}
	erase(erasetest, 30);
	cout << "Elements of erasetest after erase are: " << endl;
	for (auto it = erasetest.begin(); it != erasetest.end(); it++)
	{
		cout << *it << endl;
	}
	myvector<int> eraseiftest{ 1, 2, 3, 4, 5 };
	cout << "Elements of eraseiftest before erase_if are: " << endl;
	for (auto it = eraseiftest.begin(); it != eraseiftest.end(); it++)
	{
		cout << *it << endl;
	}
	auto remove_even = [](int i) {return i % 2 == 0; };
	erase_if(eraseiftest, remove_even);
	cout << "Elements of eraseiftest after erase_if are: " << endl;
	for (auto it = eraseiftest.begin(); it != eraseiftest.end(); it++)
	{
		cout << *it << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Insert function tests
		Works in: Visual Studio
	*/
	cout << "Insert function tests:" << endl;
	myvector<int>inserttest = { 1, 2, 3, 4, 5 };
	myvector<int>inserttest2 = { 6, 7, 8, 9, 10 };
	cout << "Elements of inserttest before insert are: " << endl;
	for (auto it = inserttest.begin(); it != inserttest.end(); it++)
	{
		cout << *it << endl;
	}
	inserttest.insert(inserttest.begin(), 0);
	cout << "Elements of inserttest after inserting 0 at start are: " << endl;
	for (auto it = inserttest.begin(); it != inserttest.end(); it++)
	{
		cout << *it << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Insert function tests (continued)
		Works in: Visual Studio
	*/
	cout << "Insert function tests (continued):" << endl;
	inserttest.insert(inserttest.begin() + 3, 3, 6);
	cout << "Elements of inserttest after inserting 3 6's at index 3 are: " << endl;
	for (auto it = inserttest.begin(); it != inserttest.end(); it++)
	{
		cout << *it << endl;
	}
	inserttest2.insert(inserttest2.end(), { 11, 12, 13, 14, 15 });
	cout << "Elements of inserttest2 after inserting initializer list are: " << endl;
	for (auto it = inserttest2.begin(); it != inserttest2.end(); it++)
	{
		cout << *it << endl;
	}
	myvector<int>inserttest3 = { 1, 2, 3, 4, 5 };
	int arr[] = { 6, 7, 8, 9, 10 };
	inserttest3.insert(inserttest3.begin(), arr, arr + 5);
	cout << "Elements of inserttest3 after inserting array are: " << endl;
	for (auto it = inserttest3.begin(); it != inserttest3.end(); it++)
	{
		cout << *it << endl;
	}
	// clear the screen and wait for input
	cout << "Press ENTER to continue..." << endl;
	cin.get();
	// clear the screen
	system("CLS");

	/*
		Move push_back and move insert tests
		Works in: OnlineGDB
	*/
	/*
	myvector<string> x{ "Hello","World", "One" };
	copy(x.begin(), x.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	string s = "Two", t = "Three";
	x.push_back(s);
	copy(x.begin(), x.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << "String s = " << s << endl;

	x.push_back(move(t));
	copy(x.begin(), x.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << "String t = " << t << endl;

	x.insert(x.begin() + 2, s);
	copy(x.begin(), x.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << "String s = " << s << endl;

	x.insert(x.begin(), move(s));
	copy(x.begin(), x.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << "String s = " << s << endl;
	*/

	/*
		Resize and non-member swap function tests
		Works in: Visual Studio
	*/
	myvector<int> vec;

	// 5 elements are inserted
	// in the vector
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	cout << "Contents of vector before resizing:"
	<< endl;

	// displaying the contents of the
	// vector before resizing
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << endl;

	// vector is resized
	vec.resize(8);

	cout << "Contents of vector after resizing:" << endl;

	// displaying the contents of
	// the vector after resizing
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	vec.resize(4);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	myvector<int> vec2 = {10, 20, 30};
	myvector<int> vec3 = { 40, 50, 60 };
	swap(vec2, vec3);
	cout << "Elements of vec2 after swap are: " << endl;
	for (auto it = vec2.begin(); it != vec2.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Elements of vec3 after swap are: " << endl;
	for (auto it = vec3.begin(); it != vec3.end(); it++)
	{
		cout << *it << endl;
	}
	myvector<int> vec4(4);
	cout << "Elements of vec4 are: " << endl;
	for (auto it = vec4.begin(); it != vec4.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}