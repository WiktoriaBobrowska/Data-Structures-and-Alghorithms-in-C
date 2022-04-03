#include <stdlib.h>
#include <stdio.h>
#include "doublyLinkedList.h"

int main(){
    node p=NULL;
    push(&p,10);
    pushEnd(&p, 20);
    pushEnd(&p, 30);
    pushAfter(&p, 20, 35);
    //pushBefore(&p, 35, 5);
    printList(p);
    saveToFile(p, "file.txt");
    //p=readFromFile("new.txt");
    return 0;
}
