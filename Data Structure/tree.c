#include <stdio.h>
#include <stdlib.h>
 
typedef struct _node {
 
    int data; //데이터
    struct _node* left; //구조체의 주소를 저장하는 포인터
    struct _node* right;
 
}Node;
 
void insertLeaf(Node** Leaf,int data)
{
 
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node** Cur,* p;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
 
    if ((*Leaf) == NULL)
    {
        (*Leaf) = newNode;
    }
    else
    {
        Cur = Leaf;
        
        while ((*Cur) != NULL)
        {
            //p = Cur;
 
            if ((*Cur)->data >= data)
            {
                Cur = &(*Cur)->left;
            }
            else
            {
                Cur = &(*Cur)->right;
            }
        }
        (*Cur) = newNode;
        /*if (p != NULL) {
            if (data < p->data) {
                p->left = newNode;
            }
            else p->right = newNode;
        }*/
 
    }
 
}
 
 
void searchLeaf(Node* Leaf)
{
    if (Leaf == NULL)
    {
        return;
    }
    else
    {
        searchLeaf(Leaf->left);
        printf("%d\n", Leaf->data);
        searchLeaf(Leaf->right);
    }
}
 
int main(void)
{
 
    Node* Head = NULL;
    insertLeaf(&Head, 1);
    insertLeaf(&Head, 2);
    insertLeaf(&Head, 3);
    insertLeaf(&Head, 4); 
    searchLeaf(Head);
 
 
 
    return 0;
}