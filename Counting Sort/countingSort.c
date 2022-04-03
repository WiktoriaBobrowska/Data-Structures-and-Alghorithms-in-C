#include <stdio.h>
#include "countingSort.h"

int maximum(int k, int* tab) {
   int max = tab[0];
   for(int i = 1; i<k; i++) {
      if(tab[i] > max)
         max = tab[i];
   }
   return max; 
}

void countingSort(int k, int* tab) {
  int max=maximum(k, tab), count[max+1], sorted[k+1];

  for (int i = 0; i <= max; ++i) count[i] = 0;
 
  for (int i = 0; i < k; i++) count[tab[i]]++;

  for (int i = 1; i <= max; i++) count[i] += count[i - 1];

  for (int i = k - 1; i >= 0; i--) {
    sorted[count[tab[i]] - 1] = tab[i];
    count[tab[i]]--;
  }
  for (int i = 0; i < k; i++) tab[i] = sorted[i];

}

void display(int* tab, int k) {
  for (int i = 0; i < k; i++) printf("%d  ", tab[i]);
  printf("\n");
}