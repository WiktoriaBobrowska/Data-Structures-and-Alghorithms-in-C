#include "binaryTree.h"
#include <stdlib.h>

void insert(node* root, char* value){
    if(*root == NULL){
        *root=(node)malloc(sizeof(treeNode));
        (*root)->word=value;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
    else if (value < (*root)->word) insert(&((*root)->left), value);
    else if (value > (*root)->word) insert(&((*root)->right), value);
}

void removeNode(node* root, char* value){
    node* toremove;
    root = find(root, value);
    if(root==NULL) return 0;
    if((*root)->left==NULL || (*root)->right==NULL) toremove=root;
    else {
        toremove=treeMax(&(*root)->left);
        (*root)->word=(*toremove)->word;
    }
    node removed=*toremove;
    if((*toremove)->left == NULL) *toremove=(*toremove)->right;
    else *toremove=(*toremove)->left;
    free(removed);
}


char* treeMin(node root){
    if(root == NULL) return 0;
    while(root->left)
        root= root->left;
    return root->word;
}
char* treeMax(node root){
    if(root == NULL) return 0;
    while(root->right)
        root= root->right;
    return root->word;
}

void printTree(node root){
    int glebokosc=0;
    int i;

    if (root==NULL) return;
    printTree(root->left, glebokosc+1);
    for (i=0; i<glebokosc); i++){
        printf("|_|");
        printf("%d\n", root->word);
        printTree(root->right, glebokosc+1)
    }
    printf("\n");
}

node* find (node* root, char* value){
  while(*root){
        if(y < (*root)->word)
            root=&(*root)->left;
        else if(value > (*root)->word)
            root=&(*root)->right;
        else return root;
    }
}
  
char* ancestor(node *root){
    node* temp;
    if(*root==NULL) return NULL;
    if(root->left) return treeMax(root->left);
    while(*root && root->left!=*temp){
        temp=root;
        root=root->parent;
    } 
    return root->word;
}

char* descendant(node root){
    node temp;
    if(*root==NULL) return NULL;
    if(root->right) return treeMin(root->right);
    while(*root && root->right!=*temp){
        temp=root;
        root=root->parent;
    } 
    return root->word;
}

node readFromFile(node* root, char* fname) {
	FILE* file = fopen(fname, "r");
	if(file==0) return printf("Cannot open the file or file does not exist");
    
	char* word = calloc(30, sizeof(char));
	while(fscanf(file, "%s ", &word) != EOF) insert(&root, word);
    
	free(word);
	fclose(file);
	return root;
}

void saveToFile0(node root, FILE* file) {
	if(root == NULL) return;
	fprintf(file, "%s ", root->word);
	saveToFile0(root->left, file);
	saveToFile0(root->right, file);
}

int saveToFile(node root, char* fname) {
	FILE* file = fopen(fname, "w");
	if(file == 0) return 0;
	saveToFile0(root, file);
	fprintf(file, "\n");
	fclose(file);
}