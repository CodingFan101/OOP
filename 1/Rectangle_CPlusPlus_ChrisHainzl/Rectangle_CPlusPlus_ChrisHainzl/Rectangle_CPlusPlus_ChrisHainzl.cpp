// Christopher Hainzl

#include <iostream>
using namespace std;

class Rectangle {
private:
	int length;
	int width;
public:
	// Default constructor
	Rectangle() {
		length = 2;
		width = 2;
	}
	
	// Constructor
	Rectangle(int x, int y) : length(x), width(y) {}
	
	// Setter and getter functions for length and width
	void setLength(int x) {
		length = x;
	}
	void setWidth(int x) {
		width = x;
	}
	int getLength() const {
		return length;
	}
	int getWidth() const {
		return width;
	}

	// Member functions for calculating area, perimeter,
	// and printing the length and width of the rectangle
	int computeArea() {
		return length * width;
	}
	int computePerimeter() {
		return 2 * (length + width);
	}
	void printLengthAndWidth() {
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl;
	}
};

int main()
{
	Rectangle rect1(5, 10);
	cout << "Contents of rect1:" << endl;
	rect1.printLengthAndWidth();
	cout << "Area of rect1: " << rect1.computeArea() << endl;
	cout << "Perimeter of rect1: " << rect1.computePerimeter() << endl;
	cout << endl;
	
	Rectangle rect2;
	cout << "Contents of rect2:" << endl;
	rect2.printLengthAndWidth();
	rect2.setLength(3);
	rect2.setWidth(4);
	cout << "Contents of rect2 after changing length to 3 and width to 4:" << endl;
	cout << "Length: " << rect2.getLength() << endl;
	cout << "Width: " << rect2.getWidth() << endl;
	cout << "Area of rect2: " << rect2.computeArea() << endl;
	cout << "Perimeter of rect2: " << rect2.computePerimeter() << endl;
	return 0;
}
