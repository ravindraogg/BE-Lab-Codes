#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 30

// SSN, Name, Dept, Designation, Sal, PhNo
struct List {
    int SSN;
    char Name[MAX];
    char Dept[MAX];
    char Designation[MAX];
    float Sal;
    char PhNo[MAX];
    struct List *prev;
    struct List *next;
};

#define MALLOC(p,s,t) \
    p = (t)malloc(s); \
    if (p == NULL) { \
        printf("Insufficient Memory\n"); \
        exit(1); \
    }

typedef struct List *NODE;

//prototypes
NODE Create(NODE, int);
NODE InsFront(NODE);
NODE InsRear(NODE);
NODE DelFront(NODE);
NODE DelRear(NODE);
void Display(NODE);
void ReadData();

//Global variable declaration
int ssn;            /* employee id  */ 
char name[MAX];     /* employee name */ 
char dept[MAX];     /* dept */
char desig[MAX];    /* designation    */
float salary;       /* salary */
char phone[MAX];    /* phone no. */

// main function
int main() {
    int choice, done;
    NODE fi;  
    int n;          /* no. of employees */
    fi = NULL;
    done = 0;
    while (!done) {
        printf("\n1.Create\t\n2.InsFront\t3.InsRear\t4.Delete Front\n5.Delete Rear\t6.Display\t7.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter No. of Employees: ");
                scanf("%d", &n);
                fi = Create(fi, n);
                break;
            case 2:
                ReadData();
                fi = InsFront(fi);
                break;
            case 3:
                ReadData(); 
                fi = InsRear(fi);
                break;
            case 4:
                fi = DelFront(fi);
                break;             
            case 5:
                fi = DelRear(fi);
                break;
            case 6:
                Display(fi);
                break;
            case 7:
                done = 1;
                break;
            default:
                printf("Invalid Choice\n\n");
                break;
        }
    }
    return 0;
}

// Read employee details function definition
void ReadData() {
    printf("Enter Employee SSN: ");
    scanf("%d", &ssn);  
    printf("Enter Employee Name: ");
    scanf("%s", name);
    printf("Enter Employee Department: ");
    scanf("%s", dept);
    printf("Enter Designation: ");
    scanf("%s", desig);
    printf("Enter Salary: ");
    scanf("%f", &salary);
    printf("Enter Phone: ");
    scanf("%s", phone); 
}

NODE Create(NODE first, int n) {
    int i;  NODE q;
    if (first == NULL) {
        for (i = 1; i <= n; i++) {
            printf("Enter Employee Data <%d>:\n", i);
            ReadData();
            first = InsFront(first);
        }
        return first;
    } else {
        printf("List already has some Employee data\n");
    }
}

// Insert employee details from front end function 
NODE InsFront(NODE first) {
    NODE q;
    MALLOC(q, sizeof(struct List), NODE);
    q->SSN = ssn;
    strcpy(q->Name, name);
    strcpy(q->Dept, dept);
    strcpy(q->Designation, desig);
    q->Sal = salary;
    strcpy(q->PhNo, phone);
    q->prev = NULL;
    q->next = first;
    if (first != NULL)
        first->prev = q;
    return q;
}

// Insert employee details from rear end function 
NODE InsRear(NODE first) {
    NODE q, cur;
    cur = first;
    while (cur->next != NULL) 
        cur = cur->next;
    MALLOC(q, sizeof(struct List), NODE);
    q->SSN = ssn;
    strcpy(q->Name, name);
    strcpy(q->Dept, dept);
    strcpy(q->Designation, desig);
    q->Sal = salary;
    strcpy(q->PhNo, phone);
    q->next = NULL;
    cur->next = q;
    q->prev = cur; 
    return first;
}

// Delete employee details from front end function 
NODE DelFront(NODE first) {
    NODE cur;
    if (first == NULL) {
        printf("Can't delete, List is Empty\n");
        return NULL;
    } else {    
        cur = first;
        first = first->next;
        if (first != NULL)
            first->prev = NULL;
        free(cur);
        return first;
    }
}

// Delete employee details from rear end function 
NODE DelRear(NODE first) {
    NODE cur = first;
    if (first == NULL) {
        printf("Can't delete, List is Empty\n");
        return NULL;
    }
    if (first->next == NULL)
        return first = NULL;
    else {
        while (cur->next != NULL) 
            cur = cur->next;
        cur->prev->next = NULL;
    }
    free(cur);       
    return first;
}

// Display employee details 
void Display(NODE first) {    
    int count = 0;
    if (first == NULL) 
        printf("\nList is Empty\n");
    else {
        while (first) {
            printf("%d\t%s\t%s\t%s\t%f\t%s\n", first->SSN, first->Name, first->Dept, first->Designation, first->Sal, first->PhNo);
            first = first->next;
            count++;
        }
        printf("Count of Nodes=%d\n", count);
    }
}