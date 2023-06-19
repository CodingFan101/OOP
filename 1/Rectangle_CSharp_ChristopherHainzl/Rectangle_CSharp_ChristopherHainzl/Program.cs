/// Author: Christopher Hainzl

using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Rectangle rect1 = new Rectangle(5, 10);
            Console.WriteLine("Contents of rect1:");
            Console.WriteLine("Area of rect1: {0}", rect1.Area());
            Console.WriteLine("Perimeter of rect1: {0}", rect1.Perimeter());
            rect1.Print();
            Console.WriteLine();
            Rectangle rect2 = new Rectangle();
            Console.WriteLine("Contents of rect2:");
            rect2.Print();
            Console.WriteLine("Now changing length of rect2 to 3, and width of rect2 to 4");
            
            /// Set length of rect2 equal to 3
            rect2.Length = 3;
            /// Set width of rect2 equal to 4
            rect2.Width = 4;
            /// Get length of rect2
            Console.WriteLine("Length of rect2: {0}", rect2.Length);
            /// Get width of rect2
            Console.WriteLine("Width of rect2: {0}", rect2.Width);
            Console.WriteLine("Area of rect2: {0}", rect2.Area());
            Console.WriteLine("Perimeter of rect1: {0}", rect2.Perimeter());
        }
    }

    class Rectangle
    {
        private int length;
        private int width;

        /// Constructors for Rectangle class
        public Rectangle()
        {
            this.length = 2;
            this.width = 2;
        }

        public Rectangle(int x, int y)
        {
            this.length = x;
            this.width = y;
        }

        /// Setters and getters for length and width

        public int Length
        {
            get { return length; }
            set { length = value; }
        }

        public int Width
        {
            get { return width; }
            set { width = value; }
        }


        /// Methods for Rectangle class
        public int Area()
        {
            return length * width;
        }

        public int Perimeter()
        {
            return 2 * (length + width);
        }

        public void Print()
        {
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Width: {0}", width);
        }
    }
}