#include <stdlib.h>
#include <stdio.h>
#include "circularLinkedList.h"

void push(node* head, int value){
    node q= malloc(sizeof(linkedListNode));

    if (*head != NULL){
        q->next=(*head)->next;
        q->data=(*head)->data;
        (*head)->next=q;
        (*head)->data=value;
    }
    else{
        q->data=value;
        q->next=q;
        *head=q;
    }
}
a
void pushEnd(node* head, int value){
    push(head, value);
    *head=(*head)->next;
}

int pop(node* head){
    int ret;
    node q;
    if (*head != NULL){
        ret=(*head)->data;
        q=(*head)->next;
        if(q==*head) *head=NULL; //1element 
        else{
            (*head)->data=q->data;
            (*head)->next=q->next;
        }
        free(q);
    }
    return ret;
}
void popEnd(node* head){
    node q = *head;
    while (q->next != *head) q=q->next;
    pop(q);
}

node* find(node *head, int value){
    node* q = *head;
    if(q=!NULL){
        while(q->next != *head && q->data !=value) q=q->next;
        if (q->data == value) return q;
        else return NULL;
    }
}

void removeNode(node* head, int value){
    node q=find(head, value);
    pop(head);
}

node readFromFile(char* fname){
    node head = NULL;
    FILE* file = fopen(fname, "r");
    int i;
    while(fscanf(file, "%d", &i) != EOF) pushEnd(&head, i);
    fclose(file);
    return head;
} // wczytaj zawartość listy z pliku

int saveToFile(node head, char* fname){
   node temp = head;
    FILE* file = fopen(fname, "w");
    if (file != 0){
        while(head->next!=temp){
            fprintf(file, "%d ",    head->data);
            head= head->next;
        }
        fclose(file);
        return 0;
    }
    else return 1;
}// zapisz zawartość listy do pliku

void removeEveryK(node* head, int k){
    int count=2; //bo count=1 to head, a na to wskazuje wskaźnik
    if (*head==NULL) printf("Lista jest pusta");
    else{
        while ((*head)->next != head){
            *head=(*head)->next;
            count++;
            if (k==count){
                pop(head);
                count=1;
            }
        }
    }
}

void diffList(node* a, node* b){
    node *h_b=b;
    node *temp;
    while((*b)->next!=*h_b){
        while(*a!=NULL){
            temp=find(a, (*b)->data);
            if (temp==0) break;
            else pop(temp);
        }
     b=&((*b)->next);
    }
}