# Christopher Hainzl
class Rectangle:
   # Constructor
   def __init__(self, length = 2, width = 2):
      self._length = length
      self._width = width
   
   # Functions for computing area and perimeter   
   def computeArea(self):
       return self._length * self._width
   
   def computePerimeter(self):
       return 2 * (self._length + self._width)
   
   # Setters and getters for length and width
   @property
   def length(self):
       return self._length
   
   @length.setter
   def length(self, length):
       self._length = length
       
   @property
   def width(self):
       return self._width
   
   @width.setter
   def width(self, width):
       self._width = width
   
   # Function to print out length and width
   def printLengthAndWidth(self):
       print("Length: ", self._length, " ; Width: ", self._width)
       
rect1 = Rectangle(10, 20)
print("Contents of rect1:")
rect1.printLengthAndWidth()
print("Area of rect1: ", rect1.computeArea())
print("Perimeter of rect1: ", rect1.computePerimeter())
print()
rect2 = Rectangle()
print("Contents of rect2:")
rect2.printLengthAndWidth()
rect2.length = 5
rect2.width = 10
print("Contents of rect2 after setting length to 5 and width to 10:")
print("Length of rect2: " , rect2.length)
print("Width of rect2: " , rect2.width)
print("Area of rect2: ", rect2.computeArea())
print("Perimeter of rect2: ", rect2.computePerimeter())
