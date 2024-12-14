#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Prototypes
int create(int);
void linearprobe(int[], int, int);
void Display(int[]);

//main function
int main() {
    int a[MAX], num, key, i;
    int ans = 1;
    printf("       Collision Handling by linear probing\n\n");
    for (i = 0; i < MAX; i++)
        a[i] = -1;
    do {
        printf("Enter the Employee ID\n");
        scanf("%4d", &num);
        key = create(num);
        linearprobe(a, key, num);
        printf("Do you wish to continue adding one more employee id?(1/0)\n");
        scanf("%d", &ans);
    } while (ans);
    Display(a);
    return 0;
}

//Create hash table function definition
int create(int num) {
    int key;
    key = num % 100;
    return key;
}

//linearprobing function definition
void linearprobe(int a[MAX], int key, int num) {
    int flag = 0, i, count = 0;
    if (a[key] == -1)
        a[key] = num;
    else {
        printf("Collision Detected!\n");
        for (i = 0; i < MAX; i++)
            if (a[i] != -1)
                count++;
        printf("Collision avoided successfully using LINEAR PROBING\n");
        if (count == MAX) {
            printf("Hash table is full\n");
            Display(a);
            exit(1);
        }
        for (i = key + 1; i < MAX; i++)
            if (a[i] == -1) {
                a[i] = num;
                flag = 1;
                break;
            }
        for (i = 0; i < key && flag == 0; i++)
            if (a[i] == -1) {
                a[i] = num;
                flag = 1;
                break;
            }
    }
}

//Display hash table function definition
void Display(int a[MAX]) {
    int i, choice;
    printf("\n1.Display All \n2. Filtered Display\n");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Complete Hash Table is\n");
        for (i = 0; i < MAX; i++)
            printf("\n%d\t%d", i, a[i]);
    } else {
        printf("Filtered Hash Table is\n");
        for (i = 0; i < MAX; i++)
            if (a[i] != -1) {
                printf("\n%d\t%d\n", i, a[i]);
                continue;
            }
    }
}
