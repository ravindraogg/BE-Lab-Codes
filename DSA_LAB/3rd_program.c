#include<stdio.h>
#include<string.h>

#define MAX_SIZE 6

// Prototypes
void push(int[], int*, int);
int pop(int[], int*);
void display(int[], int);
int palindrome(int[], int*, char[]);

// Main function
int main()
{
    int stack[MAX_SIZE], ele, deleted_item, top = -1, flag = -1, done = 0, choice;
    char palstr[MAX_SIZE];

    while (!done)
    {
        printf("\nSTACK OPERATIONS USING ARRAY");
        printf("\n1.Push\n2.Pop\n3.Palindrome\n4.Exit\n");
        printf("Enter the choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be pushed\n");
                scanf("%d", &ele);
                push(stack, &top, ele);
                display(stack, top);
                break;

            case 2:
                deleted_item = pop(stack, &top);
                if (deleted_item != -1)
                {
                    printf("Deleted Item is: %d\n", deleted_item);
                    display(stack, top);
                }
                break;

            case 3:
                printf("Enter the String\n");
                scanf("%s", palstr);
                top = -1;
                flag = palindrome(stack, &top, palstr);
                if (flag == 1)
                    printf("%s is a palindrome\n", palstr);
                else
                    printf("%s is not a palindrome\n", palstr);
                top = -1;
                break;

            case 4:
                done = 1;
                break;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

// Push function definition
void push(int stack[], int *top, int ele)
{
    if (*top == MAX_SIZE - 1)
        printf("Stack Overflow\n");
    else
    {
        ++(*top);
        stack[*top] = ele;
    }
}

// Pop function definition
int pop(int stack[], int *top)
{
    int deleted_item;
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        deleted_item = stack[*top];
        (*top)--;
        return deleted_item;
    }
}

// Display function definition
void display(int stack[], int top)
{
    int i;
    if (top == -1)
        printf("Stack is Empty\n");
    else
    {
        printf("Stack Elements are\n");
        for (i = top; i >= 0; i--)
            printf("%d\t", stack[i]);
    }
}

// Palindrome function definition
int palindrome(int stack[], int *top, char pal[])
{
    int i, p;
    for (i = 0; i < strlen(pal); i++)
        push(stack, top, pal[i]);

    for (i = 0; i < strlen(pal); i++)
    {
        if (pal[i] != pop(stack, top))
            return -1;
    }

    return 1;
}
