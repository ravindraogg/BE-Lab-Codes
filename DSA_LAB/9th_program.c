#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <ctype.h>

struct polylist {
    int coef;
    int x, y, z;
    struct polylist *link;
};

typedef struct polylist *NODE;

#define MALLOC(p, s, t) \
    p = (t)malloc(s); \
    if (p == NULL) { \
        printf("insufficient memeory\n"); \
        exit(1); \
    }

//Prototypes
NODE readPoly(NODE);
NODE padd(NODE, NODE);
float evalPoly();
NODE attach(int, int, int, int, NODE);
void printPoly(NODE);

//main function
int main() {
    NODE p1, p2, p3;
    int done = 0, choice;
    float result;
    while (!done) {
        printf("1.Polynomial Evaluation\t2.Add Polynomial\t3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                result = evalPoly();
                printf("The Polynomial Result=%8.2f\n", result);
                break;
            case 2:
                MALLOC(p1, sizeof(struct polylist), NODE);
                MALLOC(p2, sizeof(struct polylist), NODE);
                p1->link = p1;
                p2->link = p2;
                printf("Enter polynomial a \n");
                p1 = readPoly(p1);
                printf("Enter polynomial b\n");
                p2 = readPoly(p2);
                p3 = padd(p1, p2);
                printf("Resultant polynomial c\n");
                printPoly(p3);
                break;
            case 3:
                done = 1;
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}

// To read the polynomial- coeff, expx, expy, expz
NODE readPoly(NODE p) {
    int ce, expx, expy, expz;
    while (1) {
        printf("Enter the coeff and expx, expy, expz\n");
        scanf("%d%d%d%d", &ce, &expx, &expy, &expz);
        if (expx == -1)
            break;
        p = attach(ce, expx, expy, expz, p);
    }
    return p;
}

//To add the new polynomial
NODE padd(NODE p1, NODE p2) {
    NODE p3;
    NODE starta = p1;
    NODE startb = p2;
    int sum;
    MALLOC(p3, sizeof(struct polylist), NODE);
    p3->link = p3;
    p1 = p1->link;
    p2 = p2->link;
    while (p1 != starta && p2 != startb) {
        if (p1->x == p2->x && p1->y == p2->y && p1->z == p2->z) {
            sum = p1->coef + p2->coef;
            if (sum)
                p3 = attach(sum, p1->x, p1->y, p1->z, p3);
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->x < p2->x) {
            p3 = attach(p2->coef, p2->x, p2->y, p2->z, p3);
            p2 = p2->link;
        } else if (p1->x > p2->x) {
            p3 = attach(p1->coef, p1->x, p1->y, p1->z, p3);
            p1 = p1->link;
        } else if (p1->y < p2->y) {
            p3 = attach(p2->coef, p2->x, p2->y, p2->z, p3);
            p2 = p2->link;
        } else if (p1->y > p2->y) {
            p3 = attach(p1->coef, p1->x, p1->y, p1->z, p3);
            p1 = p1->link;
        } else if (p1->z < p2->z) {
            p3 = attach(p2->coef, p2->x, p2->y, p2->z, p3);
            p2 = p2->link;
        } else if (p1->z > p2->z) {
            p3 = attach(p1->coef, p1->x, p1->y, p1->z, p3);
            p1 = p1->link;
        }
    }
    for (; p1 != starta; p1 = p1->link)
        p3 = attach(p1->coef, p1->x, p1->y, p1->z, p3);
    for (; p2 != startb; p2 = p2->link)
        p3 = attach(p2->coef, p2->x, p2->y, p2->z, p3);
    return p3;
}

//To attach the polynomial
NODE attach(int c, int expx, int expy, int expz, NODE header) {
    NODE temp, q;
    MALLOC(temp, sizeof(struct polylist), NODE);
    temp->coef = c;
    temp->x = expx;
    temp->y = expy;
    temp->z = expz;
    q = header->link;
    while (q->link != header)
        q = q->link;
    q->link = temp;
    temp->link = header;
    return header;
}

// To evaluate the polynomial
float evalPoly() {
    float sum = 0;
    NODE p, start;
    float xval, yval, zval;
    int k, n = 20;
    int terms[20] = {6, 2, 2, 1, -4, 0, 1, 5, 3, 3, 1, 1, 2, 1, 5, 1, -2, 1, 1, 3};
    MALLOC(p, sizeof(struct polylist), NODE);
    p->link = p;
    printf("Enter values for x, y, z\n");
    scanf("%f%f%f", &xval, &yval, &zval);
    for (k = 0; k < n; k += 4)
        p = attach(terms[k], terms[k + 1], terms[k + 2], terms[k + 3], p);
    start = p;
    p = p->link;
    do {
        sum += p->coef * pow(xval, p->x) * pow(yval, p->y) * pow(zval, p->z);
        p = p->link;
    } while (p != start);
    return sum;
}

//To display the polynomial
void printPoly(NODE header) {
    NODE q;
    q = header->link;
    do {
        printf("%dx^%dy^%dz^%d+", q->coef, q->x, q->y, q->z);
        q = q->link;
    } while (q != header);
    printf("\n");
}
