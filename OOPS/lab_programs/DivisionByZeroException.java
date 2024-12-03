// Custom exception class (extends Exception)
class DivisionByZeroException extends Exception 
{
public DivisionByZeroException(String message)
{
        		super(message);
    	}
}

// Main class
public class Main 
{
public static void main(String[] args) 
{
        		int numerator = 10;
        		int denominator = 0;
try 
{
            		// Attempting division
            		if (denominator == 0)
{
                			// Throwing custom exception if denominator is zero
                			throw new DivisionByZeroException("Division by zero is not allowed.");
            		}
            		int result = numerator / denominator;
            		System.out.println("Result of division: " + result);
        		}
catch (DivisionByZeroException e)
{
            		// Catching and handling the custom exception
            		System.out.println("Exception caught: " + e.getMessage());
        		}
finally 
{
            	// Code in the finally block will always execute, whether an exception occurs or not
            	System.out.println("Finally block executed.");
        	}
    }
}


