#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

void push(node *head, int val){
    node q = (node)malloc(sizeof(linkedListNode));
    q->data = val;
    q->next = *head;
    *head = q;
} 

void addElement(node* head, int value){

    while((*head) -> data != INT_MAX){
        head = &((*head)->next);
        if ((*head)->data <= value) push(head, value);
    }
}

int pop(node* head){
    int ret;
    if( (*head)->data != INT_MAX){
        node temp;
	    temp = *head;
        ret =temp -> data; 
        *head = (*head)->next;
        free(temp);
    }
    return ret;
}

int popBack(node* head){
	while((*head)->next->data < INT_MAX) 
        head = &((*head)->next);
	return pop(head);
}

node* find(node *head, int val){
    while ( head != NULL && head->data != val){
        head=head->next;
    }
    return head;
}
void removeElement(node* head, int val){
    node q = find(head, val);
    pop(q);
}

void printList(node head){
    if(head->data == INT_MAX) printf("List is empty\n"); //wartownik stanowi ostatni element
	while(head->data != INT_MAX) { //nie wy�wietla wartownika
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

node readFromFile(char *fname){
    node head;
    FILE* file = fopen(fname, "r");
    int i;
    while(fscanf(file, "%d", &i) != EOF) addElement(&head, i);
    fclose(file);
    return head;
}

int saveToFile(node head, char *fname){
    node temp = head;
    FILE* file = fopen(fname, "w");
   if (file != 0){
        while(temp->data!=INT_MAX){
            fprintf(file, "%d\n", temp->data);
            temp= temp->next;
        }
        fclose(file);
        return 0;
    }
    else return 1;
}
