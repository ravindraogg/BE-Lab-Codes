// Resizable interface
interface Resizable 
{
 	void resizeWidth(int width);
    	void resizeHeight(int height);
}

// Rectangle class implementing Resizable interface
class Rectangle implements Resizable
{
	private int width;
    	private int height;

// Constructor
public Rectangle(int width, int height) 
{
this.width = width;
        	this.height = height;
}

// Implementation of resizeWidth method from Resizable interface
@Override
public void resizeWidth(int width)
{
this.width = width;
}

// Implementation of resizeHeight method from Resizable interface
@Override
public void resizeHeight(int height) 
{
this.height = height;
}

// Method to display the dimensions of the rectangle
public void displayDimensions() 
{
System.out.println("Width: " + width + ", Height: " + height);
}
}




// Main class
public class Main
{
public static void main(String[] args)
{
        		// Creating a Rectangle object
        		Rectangle rectangle = new Rectangle(10, 20);
        		System.out.println("Original Dimensions:");
        		rectangle.displayDimensions(); // Output: Width: 10, Height: 20

// Resizing the rectangle
        		rectangle.resizeWidth(15);
        		rectangle.resizeHeight(25);
        		System.out.println("Dimensions after resizing:");
        		rectangle.displayDimensions(); // Output: Width: 15, Height: 25
    	}
}
