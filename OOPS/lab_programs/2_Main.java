import java.util.Scanner;
class Stack 
{
 	private int[] elements;
    	private int top;
    	public Stack() 
{
        		elements = new int[10];
        		top = -1;
    	}
    	public boolean isEmpty() {
        	return top == -1;
}
public boolean isFull() 
{
return top == 9;
}
public void push(int element) 
{
if (isFull()) 
{
            	System.out.println("Stack is full. Cannot push more elements.");
        	}
else
{
            	elements[++top] = element;
            	System.out.println("Pushed: " + element);
        	}
}
public void pop() 
{
if (isEmpty()) 
{
            	System.out.println("Stack is empty. Cannot pop elements.");
        	}
 	else 
{
            	int poppedElement = elements[top--];
            	System.out.println("Popped: " + poppedElement);
        	}
}
public void printStack() 
{
if (isEmpty()) 
{
            	System.out.println("Stack is empty.");
        	} 
else 
{
            	System.out.print("Stack: ");
            	for (int i = 0; i <= top; i++) 
{
                		System.out.print(elements[i] + " ");
            	}
            	System.out.println();
        	}
    	}
}

public class Main
{
public static void main(String[] args) 
{
        		Stack stack = new Stack();
        		while(true)
        		{
        			System.out.println("Stack Operations");
         			System.out.println("1. Push");
          			System.out.println("2. Pop");
           			System.out.println("3. Display");
           			System.out.println("4. Exit");
            		Scanner scanner = new Scanner(System.in);
             		System.out.print("Enter your Choice: ");
        			int choice = scanner.nextInt();
           			switch(choice)
           			{
               			case 1:  System.out.println("Enter Number to push: ");
                        		int num = scanner.nextInt();
                         		stack.push(num);
                         		break;
               			case 2:  stack.pop();
                         		break;
                			case 3: stack.printStack();
                        		break;
                        		case 4:  System.exit(0);
                                		break;
                			default: System.out.println("Invalid choice ");
           			}
        		}
    	}
}
