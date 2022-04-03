#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "linkedList.h"

node Wartownik(){
    node w = (node)malloc(sizeof(linkedListNode));
    w->data = INT_MAX;
    w->next = NULL;
    return w;
}

int main(int argc, char** argv){
    node p = Wartownik();
    push(&p, 5);
    push(&p, 3);
    push(&p, 1); //1,3,5intmax
    printList(p);
    pop(&p); 
    printList(p); // 3,5,intmax
    /*addElement(&p, 7);
    printList(p);3,5,7,intmax*/
    popBack(&p);
    saveToFile(p, "new2.txt");
    printList(p); 

  return 0;
}
