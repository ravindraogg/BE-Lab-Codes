// Shape class (Superclass)
class Shape
{
public void draw() 
{
        		System.out.println("Drawing a shape");
}
	public void erase() 
{
        		System.out.println("Erasing a shape");
    	}
}

// Circle class (Subclass)
class Circle extends Shape 
{	
@Override
    	public void draw() 
{
        		System.out.println("Drawing a circle");
    	}
@Override
public void erase() 	
{
System.out.println("Erasing a circle");
}
}

// Triangle class (Subclass)
class Triangle extends Shape
{
@Override
    	public void draw() 
{
        		System.out.println("Drawing a triangle");
    	}
@Override
    	public void erase() 
{
        		System.out.println("Erasing a triangle");
    	}
}


// Square class (Subclass)
class Square extends Shape
{
	@Override
    	public void draw() 
{
        		System.out.println("Drawing a square");
    	}
@Override
    	public void erase() 
{
        		System.out.println("Erasing a square");
    	}
}

// Main class
public class Main 
{
	public static void main(String[] args) 
{
// Polymorphism: Creating objects of different subclasses using the reference of the  superclass
        	Shape shape1 = new Circle();
        	Shape shape2 = new Triangle();	
        	Shape shape3 = new Square();
// Demonstrating polymorphic behavior
        	shape1.draw(); // Calls draw() method of Circle class
        	shape1.erase(); // Calls erase() method of Circle class
shape2.draw(); // Calls draw() method of Triangle class
        	shape2.erase(); // Calls erase() method of Triangle class
shape3.draw(); // Calls draw() method of Square class
        	shape3.erase(); // Calls erase() method of Square class
    	}
}
