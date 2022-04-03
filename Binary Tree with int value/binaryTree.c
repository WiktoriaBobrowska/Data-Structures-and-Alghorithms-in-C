#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>

void insert(node* root, int value){
    if(*root == NULL){
        *root=(node)malloc(sizeof(treeNode));
        (*root)->value=value;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
    else if (value < (*root)->value) insert(&((*root)->left), value);
    else if (value > (*root)->value) insert(&((*root)->right), value);
}

int containSameValues(node* tree1, node* tree2){ //jak sa to zwraca 1, jak nie to 0

    if (*tree1 == NULL && *tree2 == NULL) return 1;
    if (*tree1 != NULL && *tree2 != NULL)
    {
        if (tree1->right != NULL){
            node p = tree1;
            while (p->left != NULL) p=p->left;
        } //p ma minimalna wartosc tree1

        if (tree2->right != NULL){
            node q = tree2;
            while (q->left != NULL) q=q->left;
        } //q ma minimalna wartosc tree2

        while (p != NULL && q != NULL && p->data == q->data)
        {
            p = descedant(*tree1, p);
            q = descedant(*tree2, q);
        }

        if (q == NULL && p == NULL) return 1;
    }
    return 0;
}