abstract class Shape 
{
// Abstract methods to calculate area and perimeter
    	abstract double calculateArea();
    	abstract double calculatePerimeter();
}

// Circle class extending Shape
class Circle extends Shape 
{
private double radius;
// Constructor for Circle class
    	public Circle(double radius) 
{
        		this.radius = radius;
    	}

// Implementation of abstract method to calculate area for Circle
@Override
double calculateArea() 
{
return Math.PI * radius * radius;
}

// Implementation of abstract method to calculate perimeter (circumference) for Circle
@Override
double calculatePerimeter() 
{
return 2 * Math.PI * radius;
}
}

// Triangle class extending Shape
class Triangle extends Shape
{
private double side1;
    	private double side2;
    	private double side3;

// Constructor for Triangle class
public Triangle(double side1, double side2, double side3)
{
this.side1 = side1;
        	this.side2 = side2;
        	this.side3 = side3;
}

// Implementation of abstract method to calculate area for Triangle using Heron's formula
@Override
double calculateArea() 
{
	double s = (side1 + side2 + side3) / 2;
        	return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// Implementation of abstract method to calculate perimeter for Triangle
@Override
double calculatePerimeter() 
{
return side1 + side2 + side3;
}
}

// Main class
public class Main
{
public static void main(String[] args) 
{
        		// Creating Circle and Triangle objects
        		Circle circle = new Circle(5);
        		Triangle triangle = new Triangle(3, 4, 5);

        		// Calculating and displaying area and perimeter for Circle
System.out.println("Circle - Area: " + circle.calculateArea() + ", Perimeter: " + circle.calculatePerimeter());

       		 // Calculating and displaying area and perimeter for Triangle
System.out.println("Triangle - Area: " + triangle.calculateArea() + ", Perimeter: " + 	triangle.calculatePerimeter());
    	}
}
