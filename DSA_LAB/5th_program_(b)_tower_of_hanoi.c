#include <stdio.h>

// Global variable declaration
int count = 0;

// Tower of Hanoi function definition
void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("Disk %d moved from %c --> %c\n", n, A, C);
        count++;
        TOH(n - 1, B, A, C);
    }
}

// Main function
int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    TOH(n, 'A', 'B', 'C');

    printf("Number of moves taken to move disks from source to destination: %d\n", count);

    return 0;
}
