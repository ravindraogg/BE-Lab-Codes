#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Global Variables
int i, top = -1;
int op1, op2, res, s[20];
char postfix[90], symb;

// push function definition
void push(int item)
{
    top = top + 1;
    s[top] = item;
}

// pop function definition
int pop()
{
    int item;
    item = s[top];
    top = top - 1;
    return item;
}

// main function
int main()
{
    printf("\nEnter a valid Postfix Expression:\n");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        symb = postfix[i];

        if (isdigit(symb))
        {
            push(symb - '0'); // Ascii value of zero(0) is 48
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (symb)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                if (op2 == 0)
                {
                    printf("Divide by zero error\n");
                    exit(0);
                }
                else
                {
                    push(op1 / op2);
                    break;
                }
            case '%':
                push(op1 % op2);
                break;
            case '^':
                push(pow(op1, op2));
                break;
            default:
                printf("Invalid Expression\n");
                exit(0);
            }
        }
    }

    res = pop();
    printf("\nResult = %d\n", res);

    return 0;
}
