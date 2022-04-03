#include <stdlib.h>
#include <stdio.h>
#include "circularDoublyLinkedList.h"

void push(node*head, int value){
    node q=malloc(sizeof(doublyLinkedListNode));
    q->data=value;
    q->next=*head;
    if(*head != NULL){
        q->prev=(*head)->prev;
        (*head)->prev=q;
    }
    else {
        q->prev=*head;
    }
    *head=q;
}

void pushEnd(node* head, int value){
     push(head, value);
    *head=(*head)->next;
} 

void pop(node* head){
    if (*head != NULL){
        node* temp = head;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        head = &((*head)->next);
        free(temp);
    }
} 

void popEnd(node* head){
    node q=*head;

    while (q->next != *head) head=&((*head)->next);
    pop(head);
}

node* find(node* head, int value){
    while((*head)->data != value) head=&((*head)->next);
    return head;
}

void pushBefore(node* head, int where, int val){
    node* q = find(head, where);
    push(q, val);
} 

void pushAfter(node* head, int where, int val){
    node* q;
    head = find(head, where);
    q=&((*head)->next);
    push(q, val);
}

void removeNode(node* head, int val){
    node *q = find(head, val);
    pop(q);
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
        while(temp->next!=head){
            fprintf(file, "%d ", temp->data);
            temp= temp->next;
        }
        fclose(file);
        return 0;
    }
    else return 1;
}