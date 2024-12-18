package mainpack; // Package declaration
import mypack.MyPackageClass; // Importing the class from mypack package
public class MainClass 
{
public static void main(String[] args) 
{
        		MyPackageClass myPackageObj = new MyPackageClass();
        		myPackageObj.display(); // Calling the display method from MyPackageClass
    	}
}

