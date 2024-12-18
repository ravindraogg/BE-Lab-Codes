class MyThread extends Thread
{
// Constructor calling the base class constructor and starting the thread
    	public MyThread(String name) 
{
        		super(name);
        		start(); // Start the thread when the constructor is called
    	}

// Run method to be executed when the thread starts
public void run() 
{
        		for (int i = 1; i <= 5; i++) 
{
            		System.out.println(Thread.currentThread().getName() + ": " + i);
            		try 
{
                			Thread.sleep(500); // Suspend the thread for 500 milliseconds
            		} 
catch (InterruptedException e) 
{
                			e.printStackTrace();
            		}
        		}
    	}
}

// Main class
public class Main
{
public static void main(String[] args)
{
        		// Main thread executing concurrently with the MyThread instance
        		for (int i = 1; i <= 5; i++) 
{
            		System.out.println("Main Thread: " + i);
            		try 
{
                			Thread.sleep(500); // Suspend the main thread for 500 milliseconds
            		}
catch (InterruptedException e)
{
                			e.printStackTrace();
            		}
        		}
// Creating an instance of MyThread
        		MyThread myThread = new MyThread("Child Thread");

        // Main thread and child thread executing concurrently
    	}
}
