class MyRunnable implements Runnable 
{
public void run() 
{
        		for (int i = 1; i <= 5; i++) 
{
            		System.out.println("Thread " + Thread.currentThread().getId() + ": " + i);
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
        		// Creating Runnable objects
        		MyRunnable myRunnable1 = new MyRunnable();
        		MyRunnable myRunnable2 = new MyRunnable();

      		// Creating threads and starting them
        		Thread thread1 = new Thread(myRunnable1);
        		Thread thread2 = new Thread(myRunnable2);

        		// Starting threads using the start() method
        		thread1.start();
        		thread2.start();
    	}
}
