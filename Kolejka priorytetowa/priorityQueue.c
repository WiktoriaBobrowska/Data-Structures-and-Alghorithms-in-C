#include <stdlib.h>
#include <stdio.h>
#include "priorityQueue.h"

void createElement(node* head, int value, int priority){
    node temp = (node)malloc(sizeof(priorityQueueNode));
    temp->data = value;
    temp->priority = priority;
    temp->next = *head; 
    *head=temp;
}

void addElement(node* head, int val, int priority){
    while((*head)!=NULL && (*head)->priority <= priority)  head=&((*head)->next);
    createElement(head, val, priority);
} 

node getHighestPriority(node* head){ //element o najwyższym priorytecie to element pierwszy
    node temp=*head;
    *head=(*head)->next;
    temp->next=NULL;
    return temp;
}

void pop(node* head){
    if(*head != NULL){
        node temp;
	    temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

/* void changeElementPriority(node* head, int val, int priority){
    node* temp = head;
    //krok1. usun ten element krok2. dodaj element o nowym priorytecie 
    while ((*temp)->data != val && (*temp) != NULL) temp=&((*temp)->next);
    if ((*temp)->data == val){
        pop(temp);
        addElement(head, val, priority);
    }
} */

void changeElementPriority(node* head, int val, int priority){

    node searcher, holder, hhead=*head;
    while((*head)->data != val) *head=(*head)->next);
    node* temp = head;
    *head=(*head)->next);
    if (*head == NULL) exit 1;
    else{ 
        if ((*head)->priority < priority){
            searcher=*head;
            while (searcher != NULL && searcher->next->priority > priority) searcher=searcher->next   
        }
        else if ((*head)->priority > priority){
            searcher=*head;
            while (searcher->next != NULL && searcher->next->priority > priority) searcher=searcher->next  
        }
        (*head)->priority=priority;
        if (searcher==*head) exit 0;
        holder=*head;
        holder->next=(*head)->next;
        (*head)->next=searcher->next;
        searcher->next=*head;
    }
    *head=hhead;
}