// Program: 3
// A class called Employee, which models an employee with an ID, name and salary, is designed as shown in the following class diagram. The method raiseSalary (percent) increases the salary by the given percentage. Develop the Employee class and suitable main method for demonstration.  
import java.util.Scanner;
public class Employee 
{
private int empId;
    	private String name;
    	private double salary;
    	public Employee(int empId, String name, double salary)
{
        		this.empId = empId;
        		this.name = name;
        		this.salary = salary;
    	}
    	public void raiseSalary(double percentage) 
{
        		if (percentage > 0) 
{
            		double raiseAmount = salary * (percentage / 100);
            		salary += raiseAmount;
        		}
    	}
    	public void displayInfo() 
{
        		System.out.println("Employee ID: " + empId);
        		System.out.println("Name: " + name);
        		System.out.println("Salary: Rs." + String.format("%.2f", salary));
    	}
    	public static void main(String[] args)
{
        		// Creating an Employee object
        		Employee emp = new Employee(1, "Dr. Harish Kumar B T", 50000.0);
         		Scanner scanner = new Scanner(System.in);
        		// Displaying employee information before raise
        		System.out.println("Employee information before raise:");
        		emp.displayInfo();
          		System.out.println("Enter the percentage of salary to raise");
          		int percentage = scanner.nextInt();
        		// Raising salary by 10%
        		emp.raiseSalary(percentage);
        		// Displaying employee information after raise
        		System.out.println("\nEmployee information after raise:");
        		emp.displayInfo();
    	}
}

