#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
//malloc() function definition using macros
#define MALLOC(p, s, t) \
    p = (t)malloc(s); \
    if (p == NULL) { \
        fprintf(stderr, "Insufficient Memory\n"); \
        exit(EXIT_FAILURE); \
    }

struct List

{
	int  USN;
	char Name[MAX];
	char Programme[MAX];
	int  Sem;
	char  PhNo[MAX];
	struct List *next;

};

typedef struct List *NODE;

//Prototypes

NODE Create   (NODE, int);
NODE InsFront (NODE);
NODE InsRear  (NODE);
NODE DelFront (NODE);
NODE DelRear  (NODE);
void Display  (NODE);
void ReadData();

//Global Variable Declaration
int usn;			/* student usn */
char sname[MAX];	/* student name */
char programme[MAX];	/* Programme */
int sem;			/* semester    */
char phone[MAX];	/* phone no. */
//main function
void main()
{
	int choice, done;
	NODE fi;			/* FIRST node */
	fi= NULL;
	done = 0;
	int n;		  /* no. of students */
	while (!done)
	{
		printf("\n1.Create\t\n2.InsFront\t3.InsRear\t4.Delete Front\n5.Delete Rear\t6.Display\t7.Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{

			case 1:	  printf("Enter No. of Students: ");
					  scanf("%d", &n);
					  fi = Create(fi, n);
					  break;

			case 2:   ReadData();
					  fi = InsFront(fi);
					  break;
			case 3:   ReadData(); 
				      fi= InsRear(fi);
					  break;
			case 4:	  fi = DelFront(fi);
				      break;
			case 5:	  fi = DelRear(fi);
					  break;
			case 6:	  Display(fi);
					  break;
			case 7:	  done=1;
					  break;
			default:  printf("Invalid Choice\n\n");
				     break;
}
	}
}
// Read student data function definition
void ReadData()
{
	printf("Enter Student USN: ");
	scanf("%d", &usn);
	printf("Enter Student Name: ");
	scanf("%s",sname);
	printf("Enter Student Programme: ");
	scanf("%s",programme);
	printf("Enter Semester: ");
	scanf("%d", &sem);
	printf("Enter Student Phone: ");
	scanf("%s",phone);
}
// Create a list of student data using front insertion definition
NODE Create(NODE first, int n)
{
	int i;
	if (first == NULL)
	{
		for (i = 1; i <= n; i++)
		{
			printf("Enter Student Data <%d>:\n", i); 
			ReadData();
			first = InsFront(first);
		}
		return first;	
	}
	else 
         printf("List already has some student data\n");
 }
// Insertion of student data from front end 
NODE InsFront (NODE first)
{
        NODE q;
MALLOC(q, sizeof(struct List), NODE);
	q->USN = usn;
	strcpy (q->Name, sname);
	strcpy(q->Programme, programme);
	q->Sem = sem;
	strcpy(q->PhNo, phone);
	q->next = first;
	first = q;
	return first;
}
// Insertion of student data from rear end 
NODE InsRear (NODE first)
{
	NODE q, t = first;
	MALLOC(q, sizeof(struct List), NODE);
	q->USN = usn;
	strcpy (q->Name, sname);
	strcpy(q->Programme, programme);
	q->Sem = sem;
	strcpy(q->PhNo, phone);
	q->next = NULL; 	
	if (!first) 
          first = q;
	else 
	{
		while (t->next)
		    t = t->next;
		t->next = q;		/* goto last node */
	}
	return first;
}
// Deletion of student data from front end 
NODE DelFront (NODE first)
{
	NODE te;
	if(first == NULL)
		printf("Can't delete, List is Empty\n");
	else
{
    		te = first;
		first= first->next;
		free(te);
}
	return first;
}
// Deletion of student data from rear end 
NODE DelRear (NODE first)
{
	NODE cur, pred;
	if(first == NULL)
	{
		printf("Can't delete, List is Empty\n");
		return first;
	}
	if(first->next == NULL)
		return first=NULL;

	// more than one node */
	cur = first;
	while (cur->next != NULL)
	{
		pred = cur;
		cur = cur->next;	
	}
	free(cur);
	pred->next = NULL;
	return first;
}
/* Displays the contents of the list */
void Display (NODE first)
{
  int count =0;
	while (first)
	{
printf("%d\t%s\t%s\t%d\t%s\n", first->USN, first->Name, first->Programme, first->Sem, first->PhNo);
		first = first->next;
		count++;
	}
	printf("Count of Nodes = %d\n", count);
}
