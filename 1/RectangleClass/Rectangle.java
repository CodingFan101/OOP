import java.io.*;
/**
 * Rectangle class implemented in Java.
 *
 * Christopher Hainzl
 */
class Rectangle
{
    private int length;
    private int width;

    /**
     * Constructors for objects of class Rectangle
     */
    public Rectangle()
    {
        this.length = 2;
        this.width = 2;
    }
    
    public Rectangle(int x, int y){
        this.length = x;
        this.width = y;
    }
    
    /**
    Setter and getter functions for length and width.
    */
    
    public void setLength(int x){
        length = x;
    }
    
    public void setWidth(int y){
        width = y;
    }
    
    public int getLength(){
        return length;
    }
    
    public int getWidth(){
        return width;
    }
    
    /**
     Functions to compute area and perimeter.
    */
    public int computeArea()
    {
        return length * width;
    }
    
    public int computePerimeter(){
        return 2 * (length + width);
    }
    
    /**
     Function to print out length and width.
    */
    public void printLengthAndWidth(){
        System.out.println("Length: " + length);
        System.out.println("Width: " + width);
    }
}
