// OuterClass containing an inner class Inner
class OuterClass
{
	// Outer class display method
    	public void display() 
{
        		System.out.println("OuterClass display method");
    	}

    	// Inner class
    	class Inner
 	{
        		// Inner class display method
        		public void display() 
{
            		System.out.println("InnerClass display method");
        		}
    	}
}

// Main class
public class Main 
{
public static void main(String[] args) 
{
        		// Creating an object of OuterClass
        		OuterClass outerObject = new OuterClass();

        		// Calling display method of OuterClass
        		outerObject.display(); // Output: OuterClass display method

        		// Creating an object of Inner class (inside OuterClass)
        		OuterClass.Inner innerObject = outerObject.new Inner();

        		// Calling display method of Inner class
       		innerObject.display(); // Output: InnerClass display method
    	}
}
