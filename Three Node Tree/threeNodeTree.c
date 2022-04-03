#include <stdlib.h>
#include "threeNodeTree.h"

void append(node* root, float value){
    if(*root == NULL){
        *root=(node)malloc(sizeof(threeNodesTree);
        (*root)->data=value;
        (*root)->left=NULL;
        (*root)->right=NULL;
	    (*root)->middle=NULL;
    }
    else if (value < ((*root)->data/3)) insert(&((*root)->left), value);
    else if (value > ((*root)->data/3) && value < ((2*(*root)->data)/3) ) insert(&((*root)->middle), value);
    else if (value > ((2*(*root)->data)/3)) insert(&((*root)->right), value);
}

node* find(node* root, float value){
  
    while(*root != NULL){
        if (value < ((*root)->data/3)) root=&(*root)->left; 
        else if (value > ((*root)->data/3) && value < ((2*(*root)->data)/3)) root=&(*root)->middle;
        else if (value > ((2*(*root)->data)/3)) root=&(*root)->right;
    }
    return root;
}