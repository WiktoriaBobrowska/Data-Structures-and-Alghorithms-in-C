#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "countingSort.h"

int main(){
    srand(time(NULL));
    int k, size=100;
    int tab[size];
    for(int i=0; i<size; i++) tab[i]=rand()%10;

    display(tab,size);
    printf("Dla ilu elementów posortować? ");
    scanf("%d", &k);

    countingSort(k,tab);//tablica ma 100 elementow, sortuje dla k elementow
    display(tab,k);
    return 0;
}