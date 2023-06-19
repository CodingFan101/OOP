import java.io.*;
/**
 Testing Rectangle class implementation in Java.
 */
public class RectangleTest
{
    public static void main(String args[]){
        Rectangle rect1 = new Rectangle(5, 10);
        System.out.println("Contents of rect1:");
        rect1.printLengthAndWidth();
        System.out.println("Area of rect1: " + rect1.computeArea());
        System.out.println("Perimeter of rect1: " + rect1.computePerimeter());
        System.out.println();
        Rectangle rect2 = new Rectangle();
        System.out.println("Contents of rect2:");
        rect2.printLengthAndWidth();
        rect2.setLength(3);
        rect2.setWidth(4);
        System.out.println("Contents of rect2 after changing length to 3 and width to 4:");
        System.out.println("Length of rect2: " + rect2.getLength());
        System.out.println("Width of rect2: " + rect2.getWidth());
        System.out.println("Area of rect2: " + rect2.computeArea());
        System.out.println("Perimeter of rect2: " + rect2.computePerimeter());
    }
}
