#include <stdio.h>
#include <string.h>
#include "heapSort.h"

void Heapify(char** tab, int i, int HeapSize) {

    int largest, l=2*i+1, r=2*i+2;
    char x[100];
 
    if (l < HeapSize && (strcmp(tab[l], tab[i]) > 0)) largest = l;
    else largest = i;
    if (r < HeapSize && (strcmp(tab[r], tab[largest]) > 0)) largest = r;

    if (largest != i){
        strcpy(x, tab[i]);
        strcpy(tab[i], tab[largest]);
        strcpy(tab[largest], x);
        Heapify(tab, largest, HeapSize);
    }
}

void BuildHeap(char** tab, int n){
    for (int i= (n - 1 )/ 2 ; i >= 0; i--) Heapify(tab, i, n);
}

void HeapSort(char** tab, int n) {

    int HeapSize = n;
    char *x =calloc(10, sizeof(char)); 
    BuildHeap(tab, n);
    for (int i= n - 1 ; i > 0; i--) {
        if(sizeof(tab) > sizeof(x)) x=realloc(x, 2*sizeof(char));
        strcpy(x, tab[0]);
        strcpy(tab[0], tab[i]);
        strcpy(tab[i], x);
        Heapify(tab, 0, HeapSize--);
    }
    free(x);
}
int size(char* word){
    int offset = 0;
    int count = 0;

    while (*(word + offset) != '\0')
    {
        count++;
        offset++;
    }
    return count;
} //dodatkowe przesunięcie wskaźnika

void display(char* tab[], int n){
    for(int i=0;i<n;i++) printf("%s ", tab[i]);
    printf("\n");
}