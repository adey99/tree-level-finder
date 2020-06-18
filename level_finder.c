#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/* A tree node structure */
struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

/* Helper function for getLevel().  It returns level of the data if data is
   present in tree, otherwise returns 0.*/
int getLevelUtil(struct Tree *node, int data, int level)
{
    if (node == NULL)
        return 0;

    if (node->data == data)
        return level;

    int downlevel = getLevelUtil(node->left, data, level+1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(node->right, data, level+1);
    return downlevel;
}
/* Utility function to create a new Binary Tree node */
struct Tree* newNode(int data)
{
    struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
struct Tree *create()
{
    struct Tree *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);

    if(x==-1)
        return NULL;

    p=(struct Tree*)malloc(sizeof(struct Tree));
    p->data=x;

    printf("Enter left child of %d:\n",x);
    p->left=create();

    printf("Enter right child of %d:\n",x);
    p->right=create();

    return p;
}

/* Driver function to test above functions */
int main()
{
    struct Tree *root = (struct Tree *)malloc(sizeof(struct Tree));
    if(root==NULL){
    	printf("\nMemory not assigned:");
      return 0;
    }
    int x,level;

    /* Constructing tree given in the above figure
    root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->left = newNode(2);
    root->left->right = newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(6); */

    root=create();

    printf("\nEnter the node to be searched:");
    scanf("%d",&x);
    level=getLevelUtil(root,x,1);
    if(level)
    	printf("Level of %d is %d\n",x,level);
    else
    	printf("%d is not present in tree\n",x);
    getch();
    return 0;
}
