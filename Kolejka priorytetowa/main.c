#include <stdlib.h>
#include <stdio.h>
#include "priorityQueue.h"

void printList(node head){
    while( head != NULL) {
		printf("%d ", head->data);
	    head = head->next;
	}
	printf("\n");
}

int main(){
    
    node p=NULL;
    //node thehighest=NULL;

    addElement(&p, 14, 1);
    addElement(&p, 10, 3);
    addElement(&p, 1, 2);
    //thehighest = getHighestPriority(&p);
    //printList(thehighest);
    printList(p);
    //ZAMIANA PRIORYTETU WART 1 Z 2 NA 5
    changeElementPriority(&p, 2, 5);
    printList(p);
    return 0;
}