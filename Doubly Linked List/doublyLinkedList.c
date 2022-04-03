#include <stdlib.h>
#include <stdio.h>
#include "doublyLinkedList.h"

//Nieposortowana
void push(node* head, int val){
    node q=malloc(sizeof(doublyLinkedListNode));
    q->data=val;
    q->next=*head;
    if(*head != NULL){
        q->prev=(*head)->prev;
        (*head)->prev=q;
    }
    else {
        q->prev=NULL;
        *head=q;
    }
}
void pushEnd(node* head, int val){
    while(*head != NULL){
        head=&((*head)->next);
    }
    push(head, val);
}

int pop(node* head){
    int ret;
    node q=*head;
    if (q != NULL){
        ret=q->data;
        *head=q->next;
        if(*head != NULL) (*head)->prev=NULL;
        free(q);
    }
    else{
        printf("List is empty");
        ret=1; //1 jako b��d, exit status
    }
    return ret;
}

int popEnd(node* head){
    if(*head != NULL){
        while((*head)->next != NULL) head=&((*head)->next);
    }
    return pop(head);
}

node* find(node* head, int val){
    while((*head) != NULL && (*head)->data != val) head=&((*head)->next);
    return head;
}

void pushBefore(node* head, int where, int val){
    head= find(head, where);
    node *q=head;
    push(q, val);
} //je�li lista jest pusta to dodaje jako pierwszy, nie dzialaaaaa

void pushAfter(node* head, int where, int val){
    node* q;
    head = find(head, where);
    q=&((*head)->next);
    push(q, val);
}

int removeNode(node* head, int val){
    node *q = find(head, val);
    return pop(q);
} 

node readFromFile(char *fname){
    node head = NULL;
    FILE* file = fopen(fname, "r");
    int i;
    while(fscanf(file, "%d", &i) != EOF) pushEnd(&head, i);
    fclose(file);
    return head;
}

int saveToFile(node head, char *fname){
   node temp = head;
    FILE* file = fopen(fname, "w");
   if (file != 0){
        while(temp!=NULL){
            fprintf(file, "%d ", temp->data);
            temp= temp->next;
        }
        fclose(file);
        return 0;
    }
    else return 1;
}

void printList(node head){
    while(head != NULL) {    
        printf("%d ", head->data);  
        head = head->next; 
    }
}

// LISTA POSORTOWANA    
void addElementInOrder(node* head, int value){
    while(*head != NULL && (*head)->data <= value) head=&((*head)->next);
    push(head, value);
}

node* findInOrder(node* head, int value){
    while((*head) != NULL && (*head)->data != value) head=&((*head)->next);
    return head;
}
void removeElementInOrder(node* head, node element){
    while ((*head)!= NULL && (*head) != element) head=&((*head)->next);
    pop(head);
}

node readFromFileInOrder(char *fname){
    node head = NULL;
    FILE* file = fopen(fname, "r");
    int i;
    while(fscanf(file, "%d", &i) != EOF) addElementInOrder(&head, i);
    fclose(file);
    return head;
}
