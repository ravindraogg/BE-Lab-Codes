#include<stdio.h>
void Enqueue();
void dequeue();
void display();
# define max 5
int cqueue[max];
int front=-1,rear=-1;
int main(){
    printf("------------ciruclar queue operations------------------\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    int choice,done=0;
    while(!done)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:Enqueue();
                break;
            case 2:dequeue();
                break;
            case 3:display();
                break;
            case 4:printf("------------GOOD BYE-------------------\n");
                    done=1;
                    break;
            default:printf("Invalid choice\n");
        }
    }
}
void Enqueue()
{
    if(front==0 && rear==max-1)
        printf("Circular queue is full, can't push elements\n");
    else{
         int ele;
        printf("Enter the element to be added to the queue:");
        scanf("%d",&ele);
        if(front==-1)
            front=0;
        rear=(rear+1)%max;
        cqueue[rear]=ele;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
        printf("Circular queue is empty, can't delete elements\n");
    else if(front==rear)
      {  printf("The dequeued element is :%d\n",cqueue[front]);
            front=-1;
            rear=-1;
      }
      else{
        printf("The dequeued element is :%d\n",cqueue[front]);
        front=(front+1)%max;
      }
}
void display()
{
        int i;
    if(front==-1 && rear==-1)
        printf("The circular queue is empty\n");

    else if(front>rear)
    {
        printf("The circular queue elements are:");
        for(i=front;i<=max;i++)
            printf("%d\t",cqueue[i]);
        for(i=rear;i<=max;i++)
            printf("%d\t",cqueue[i]);
    }
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",cqueue[i]);

    }
}  