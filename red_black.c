#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int color, key, id;
    struct _node *left, *right, *p;
} tree;
tree *root;
int n, inp[222222];
void left_rotate(tree *x)
{
    tree *y=x->right;
    x->right=y->left;
    if (y->left)
        y->left->p=x;
    y->p=x->p;
    if (!x->p)
        root=y;
    else if (x==x->p->left)
        x->p->left=y;
    else
        x->p->right=y;
    y->left=x;
    x->p=y;
}
void right_rotate(tree *x)
{
    tree *y=x->left;
    x->left=y->right;
    if (y->right)
        y->right->p=x;
    y->p=x->p;
    if (!x->p)
        root=y;
    else if (x==x->p->left)
        x->p->left=y;
    else
        x->p->right=y;
    y->right=x;
    x->p=y;
}
void RB_insert_fixup(tree *z)
{
    while (z->p->color==0)          //red == 0
    {
        if (z->p==z->p->p->left)
        {
            tree *y=z->p->p->right;
            if (y->color==0)
            {
                z->p->color=1;      //black == 1
                y->color=1;
                z->p->p->color=1;
                z=z->p->p;
            }
            else
            {
                if (z==z->p->right)
                {
                    z=z->p;
                    left_rotate(z);
                }
                z->p->color=1;
                z->p->p->color=0;
                right_rotate(z->p->p);
            }
        }
        else
        {
            tree *y=z->p->p->left;
            if (y->color==0)
            {
                z->p->color=1;
                y->color=1;
                z->p->p->color=0;
                z=z->p->p;
            }
            else
            {
                if (z==z->p->right)
                {
                    z=z->p;
                    left_rotate(z);
                }
                z->p->color=1;
                z->p->p->color=0;
                right_rotate(z->p->p);
            }
        }
    }
}
void RB_insert(int key, int id)
{
    tree *y=NULL, *x=root, *z=(tree *) malloc(sizeof(tree));
    z->color=0;
    z->id=id;
    z->key=key;
    z->left=z->right=z->p=NULL;
    while (x)
    {
        y=x;
        if (z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->p=y;
    if (!y)
        root=z;
    else if (z->key<y->key)
        y->left=z;
    else
        y->right=z;
    z->left=z->right=NULL;
    z->color=0;
    RB_insert_fixup(z);
}
void inorder(tree *x)
{
    if (x)
    {
        inorder(x->left);
        printf("%d ", x->key);
        inorder(x->right);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &inp[i]);
        RB_insert(inp[i], i);
    }
    //inorder(root);
}
