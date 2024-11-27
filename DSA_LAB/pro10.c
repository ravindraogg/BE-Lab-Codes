#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30

struct tree
{
        int info;
        struct tree *left;
        struct tree *right;
};

#define MALLOC(p, s, t) \
        p = (t)malloc(s);   \
        if (p == NULL)      \
        {                    \
                printf("Insufficient memory\n"); \
                exit(1);           \
        }

typedef struct tree *NODE;

// Prototypes
NODE create(NODE, int);
NODE createtree(NODE, int);
void Preorder(NODE);
void Postorder(NODE);
void Inorder(NODE);
int search(NODE, int);

// Global Variable Declaration
int n;

// Main function
int main()
{
        int choice, done, flag, key;
        NODE p;
        p = NULL;
        done = 0;

        while (!done)
        {
                printf("1.Create\t2.Preorder\t3.Inorder\t4.Postorder\t5.Search\t6.Exit\n");
                printf("Enter the choice\n");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        printf("Enter No. of Data Elements\n");
                        scanf("%d", &n);
                        p = create(p, n);
                        break;
                case 2:
                        Preorder(p);
                        printf("\n");
                        break;
                case 3:
                        Inorder(p);
                        printf("\n");
                        break;
                case 4:
                        Postorder(p);
                        printf("\n");
                        break;
                case 5:
                        printf("Enter the Key to Search\n");
                        scanf("%d", &key);
                        flag = search(p, key);
                        if (flag == 1)
                                printf("Key Found\n");
                        else
                                printf("Key not Found\n");
                        break;
                case 6:
                        done = 1;
                        break;
                default:
                        printf("Invalid Choice\n");
                }
        }

        return 0;
}

// Read function definition to create BST
NODE create(NODE root, int n)
{
        int i, e;
        NODE q;

        if (root == NULL)
        {
                for (i = 1; i <= n; i++)
                {
                        printf("Enter Data element\n");
                        scanf("%d", &e);
                        root = createtree(root, e);
                }
                return root;
        }
        else
        {
                printf("Tree already has some data\n");
                return root; // Added return statement
        }
}

// Binary search tree creation function definition
NODE createtree(NODE p, int e)
{
        if (p == NULL)
        {
                MALLOC(p, sizeof(struct tree), NODE);
                p->info = e;
                p->left = p->right = NULL;
        }
        else if (e == p->info)
                printf("Duplicate Entry\n");
        else if (e < p->info)
                p->left = createtree(p->left, e);
        else
                p->right = createtree(p->right, e);

        return p;
}

// Search the key element in the BST
int search(NODE p, int key)
{
        if (p == NULL)
                return 0;
        else if (key == p->info)
                return 1;
        else if (key < p->info)
                return search(p->left, key);
        else
                return search(p->right, key);
}

// Preorder Traversal - VLR
void Preorder(NODE p)
{
        if (p != NULL)
        {
                printf("%d\t", p->info);
                Preorder(p->left);
                Preorder(p->right);
        }
}

// Inorder Traversal - LVR
void Inorder(NODE p)
{
        if (p != NULL)
        {
                Inorder(p->left);
                printf("%d\t", p->info);
                Inorder(p->right);
        }
}

// Postorder Traversal - LRV
void Postorder(NODE p)
{
        if (p != NULL)
        {
                Postorder(p->left);
                Postorder(p->right);
                printf("%d\t", p->info);
        }
}