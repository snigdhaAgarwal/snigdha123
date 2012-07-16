#include<stdio.h>
#include<stdlib.h>
//#include "tree.h"
typedef struct tree
{

    struct tree* right;
    struct tree* left;
    int data;
}tree;
tree* insert(int x,tree* t)
{
    tree *t1;
    tree *new;
    new=(tree*)malloc(sizeof(tree));
    t1=t;
    new->data=x;
    new->left=NULL;
    new->right=NULL;
    if(t1==NULL)
        t=new;
    else
    {
        while(1)
        {
            if(t1->data>x)
            {
                if(t1->left!=NULL)
                    t1=t1->left;
                else
                {
                    t1->left=new;
                    break;
                }
            }
            else 
            {
                if(t1->right!=NULL)
                    t1=t1->right;
                else
                {
                    t1->right=new;
                    break;
                }
            }
        }
    }
    return t;
}
void inorder(tree* T)
{
    if(T == NULL)
        return;
    inorder(T->left);
    printf("%d ",T->data);
    inorder(T->right);
}
void postorder(tree* t)
{
    if(t==NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    printf("%d ",t->data);
}
void preorder(tree* t)
{
    if(t==NULL)
        return;
    printf("%d ",t->data);
    preorder(t->left);
    preorder(t->right);
}
int main()
{
    tree *t=NULL;
    int i,n;
    //printf("hello");
    for(i=0;i<6;i++)
    {
        scanf("%d",&n);
//        printf("helllo");
        t=insert(n,t);
    }
    inorder(t);
    printf("\n");
    postorder(t);
    printf("\n");
    preorder(t);
    return 0;
}
