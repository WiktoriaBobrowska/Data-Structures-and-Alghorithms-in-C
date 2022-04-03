#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

void push(node **head, int val){
    node* q = (node*)malloc(sizeof(node));
    q->data = val;
    q->next = *head;
    *head = q;
} 

void pushEnd(node **head, int val){
    while (*head != NULL) head=&((*head)->next);
    push(head,val);
} 

void pop(node **head){
    if( *head != NULL){
        node* temp;
	    temp = *head;
        *head = (*head)->next;
        free(temp);
    }
} 

void popEnd(node **head) {
	while((*head)->next != NULL) 
        head = &((*head)->next);
	pop(head);
}

node* find(node *head, int val){
    while ( head != NULL && head->data != val){
        head=head->next;
    }
    return head;
}

void pushBefore(node **head, int where, int val){
    while(*head != NULL && (*head)->data != where) head = &((*head)->next);
    push(head, val);
}

void pushAfter(node **head, int where, int val){
    while(*head != NULL && (*head)->data != where) head = &((*head)->next);
    head = &((*head)->next);
    push(head, val);
}
void removeNode(node **head, int val){
    while (head !=NULL && (*head)->data != val) head=&((*head)->next);
    pop(head);
} 

  node* readFromFile(char *fname){
    node* head = NULL;
    FILE* file = fopen(fname, "r");
    int i;
    while(fscanf(file, "%d", &i) != EOF) pushEnd(&head, i);
    fclose(file);
    return head;
}

int saveToFile(node *head, char *fname){
   node* temp = head;
    FILE* file = fopen(fname, "w");
   if (file != 0){
        while(temp!=NULL){
            fprintf(file, "%d\n", temp->data);
            temp= temp->next;
        }
        fclose(file);
        return 0;
    }
    else return 1;
}
void removeAll_iteratively(node **head, int val){

     while ((*head) != NULL){
        if ((*head)->data == val) pop(head);
        else head = &((*head)->next);
    }
} 

void removeAll_recursively(node **head, int val){
    if(*head != NULL){
        if((*head)-> data == val) pop(head);
        else head = &((*head)->next);
        removeAll_recursively(head, val);
    }
}

int findMostCommon(node *head){
    if(head==NULL) return 0;
    node* temp = head;
    int max = -1, result, count;

    while (temp != NULL){
        node* temp1 = temp;
        count = 0;
        while (temp1 != NULL) {
            if (temp->data == temp1->data) count++;
            temp1 = temp1->next;
        }

        if (max < count){
            result = temp->data;
            max = count;
        }
        temp = temp->next;
    }
    return result;
} 

void usunniepodz(node **l, int k){
    node **temp;
    while ((*l)!=NULL){
        if(((*l)->data)%k != 0){
            temp=l;
            pop(l);
            l=temp;
        }
        else l=&((*l)->next);
    }
}

void revert_iteratively(node **head){
    node* curr = *head;
    node* prev=NULL;
    node* next = NULL;
    prev = NULL;
    while(curr != NULL){
      next = curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }
    *head = prev;
} 

 void revert_recursively(node **head){
    node* temphead = *head;
    if (*head != NULL && (*head)->next != NULL){
        *head = (*head)->next;
        revert_recursively(head);
        temphead->next->next = temphead;
        temphead->next = NULL;
    }
}

