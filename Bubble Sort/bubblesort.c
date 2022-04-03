#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define REPEAT 1000
#define SIZE 10000

int substitution_bubble =0,  substitution_quick = 0, substitution_insert = 0, substitution_shell = 0;
int comparison_bubble = 0, comparison_quick = 0, comparison_insert = 0, comparison_shell = 0;

void bubblesort(int* tab, int n) {
    substitution_bubble = 0;
    comparison_bubble = 0;

    int bufor;
    for (int i = 1; i < n; i++){
        for (int j = n - 1; j >= 1; j--){
            comparison_bubble++;
            if (*(tab + j) < *(tab + j - 1)){

                bufor = *(tab + j - 1);
                *(tab + j - 1) = *(tab + j);
                *(tab + j) = bufor;
                substitution_bubble += 3;
            }
        }
    }
}

void quicksort(int* tab, int l, int p) {
    substitution_quick = 0;
    comparison_quick = 0;

    int x = *(tab + (l + p) / 2);
    substitution_quick += 1;
    int i, j;
    i = l;
    j = p;
    do
    {
        while (*(tab + i) < x) {
            i++;
            comparison_quick++;
        }
        while (*(tab + j) > x)
        {
            j--;
            comparison_quick++;
        }
        if (i <= j)
        {
            x = *(tab + i);
            *(tab + i) = *(tab + j);
            *(tab + j) = x;
            i++;
            j--;
            substitution_quick += 3;
        }
    } while (i <= j);
    if (j > l) quicksort(tab, l, j);
    if (i < p) quicksort(tab, i, p);
}

void shellSort(int* tab, int n) {
    substitution_shell = 0;
    comparison_shell = 0;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            comparison_shell++;
            substitution_shell++;
            int temp = *(tab + i);
            int j;
            for (j = i; j >= gap && *(tab + j - gap) > temp; j -= gap) {
                *(tab + j) = *(tab + j - gap);
                comparison_shell++;
                substitution_shell++;
            }
            *(tab + j) = temp;
            substitution_shell++;
        }
    }
}

void insertionSort(int* tab, int n) {
    substitution_insert = 0;
    comparison_insert = 0;

    int i, key, j;
    for (i = 1; i < n; i++) {
        substitution_insert++;
        comparison_insert++;
            key = *(tab + i);
        j = i - 1;
        while (j >= 0 && *(tab + j) > key) {
            substitution_insert++;
            comparison_insert++;
            *(tab + j + 1) = *(tab + j);
            j = j - 1;
        }
        *(tab + j) = key;
        substitution_insert++;
    }
}

int main() {

    //podstawienia minimalne, max, srednie i sumy 
    int minSub_bubble = INT_MAX, minSub_quick = INT_MAX, minSub_shell = INT_MAX, minSub_insert = INT_MAX;
    int maxSub_bubble = -INT_MAX, maxSub_quick = -INT_MAX, maxSub_shell = -INT_MAX, maxSub_insert = -INT_MAX;
    int sumSub_bubble = 0, sumSub_quick = 0, sumSub_shell = 0, sumSub_insert = 0;
    int meanSub_bubble = 0, meanSub_quick = 0, meanSub_shell = 0, meanSub_insert = 0;
    //porownania minimalne, max, srednie i sumy 
    int minCom_bubble = INT_MAX, minCom_quick = INT_MAX, minCom_shell = INT_MAX, minCom_insert = INT_MAX;
    int maxCom_bubble = -INT_MAX, maxCom_quick = -INT_MAX, maxCom_shell = -INT_MAX, maxCom_insert = -INT_MAX;
    int sumCom_bubble = 0, sumCom_quick = 0, sumCom_shell = 0, sumCom_insert = 0;
    int meanCom_bubble = 0, meanCom_quick = 0, meanCom_shell = 0, meanCom_insert = 0;

    srand(time(NULL));
    int* bubble = (int*)calloc(SIZE, sizeof(int));
    int* shell = (int*)calloc(SIZE, sizeof(int));
    int* quick = (int*)calloc(SIZE, sizeof(int));
    int* insert = (int*)calloc(SIZE, sizeof(int));

    //inicjalizacja liczb losowych
    for (int i = 0; i < REPEAT; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(bubble + i) = rand() % 100 + 1;
        }
        //przepisanie tablicy, by sortowania byly na tych samych wartosciach
        for (int k = 0; k < SIZE; k++) {
            *(bubble + k) = *(bubble + k);
            *(quick + k) = *(bubble + k);
            *(shell + k) = *(bubble + k);
            *(insert + k) = *(bubble + k);
        }

        bubblesort(bubble, SIZE);
        quicksort(quick, 0, SIZE - 1);
        shellSort(shell, SIZE);
        insertionSort(insert, SIZE);

        if (comparison_bubble > maxCom_bubble) maxCom_bubble = comparison_bubble;
        if (substitution_bubble > maxSub_bubble) maxSub_bubble = substitution_bubble;
        if (comparison_bubble < minCom_bubble) minCom_bubble = comparison_bubble;
        if (substitution_bubble < minSub_bubble) minSub_bubble = substitution_bubble;
        if (comparison_quick > maxCom_quick) maxCom_quick = comparison_quick;
        if (substitution_quick > maxSub_quick) maxSub_quick = substitution_quick;
        if (comparison_quick < minCom_quick) minCom_quick = comparison_quick;
        if (substitution_quick < minSub_quick) minSub_quick = substitution_quick;
        if (comparison_shell > maxCom_shell) maxCom_shell = comparison_shell;
        if (substitution_shell > maxSub_shell) maxSub_shell = substitution_shell;
        if (comparison_shell < minCom_shell) minCom_shell = comparison_shell;
        if (substitution_shell < minSub_shell) minSub_shell = substitution_shell;
        if (comparison_insert > maxCom_insert) maxCom_insert = comparison_insert;
        if (substitution_insert > maxSub_insert) maxSub_insert = substitution_insert;
        if (comparison_insert < minCom_insert) minCom_insert = comparison_insert;
        if (substitution_insert < minSub_insert) minSub_insert = substitution_insert;
        //sumy
        sumCom_bubble += comparison_bubble;
        sumSub_bubble += substitution_bubble;
        sumCom_quick += comparison_quick;
        sumSub_quick += substitution_quick;
        sumCom_shell += comparison_shell;
        sumSub_shell += substitution_shell;
        sumCom_insert += comparison_insert;
        sumSub_insert += substitution_insert;
    }

    meanCom_bubble = sumCom_bubble / REPEAT;
    meanSub_bubble = sumSub_bubble / REPEAT;

    meanCom_quick = sumCom_quick / REPEAT;
    meanSub_quick = sumSub_quick / REPEAT;

    meanCom_shell = sumCom_shell / REPEAT;
    meanSub_shell = sumSub_shell / REPEAT;

    meanCom_insert = sumCom_insert / REPEAT;
    meanSub_insert = sumSub_insert / REPEAT;

    printf("BUBBLESORT---------------------------------------------------\n");
    printf("Podstawienia:   minimalna:%d,  maksymalna:%d,  srednia:%d\n", minSub_bubble, maxSub_bubble, meanSub_bubble);
    printf("Porowanania:    minimalna:%d,  maksymalna:%d,  srednia:%d\n", minCom_bubble, maxCom_bubble, meanSub_bubble);
    printf("QUICKSORT----------------------------------------------------\n");
    printf("Podstawienia:   minimalna:%d,  maksymalna:%d, srednia:%d\n", minSub_quick, maxSub_quick, meanSub_quick);
    printf("Porowanania:    minimalna:%d,  maksymalna:%d,  srednia:%d\n", minCom_quick, maxCom_quick, meanSub_quick);
    printf("SHELLSORT----------------------------------------------------\n");
    printf("Podstawienia:   minimalna:%d,  maksymalna:%d,  srednia:%d\n", minSub_shell, maxSub_shell, meanSub_shell);
    printf("Porowanania:    minimalna:%d,  maksymalna:%d,  srednia:%d\n", minCom_shell, maxCom_shell, meanSub_shell);
    printf("INSERTSORT---------------------------------------------------\n");
    printf("Podstawienia:   minimalna:%d,  maksymalna:%d,  srednia:%d\n", minSub_insert, maxSub_insert, meanSub_insert);
    printf("Porowanania:    minimalna:%d,  maksymalna:%d,  srednia:%d\n", minCom_insert, maxCom_insert, meanSub_insert);
    printf("-------------------------------------------------------------");

    free(bubble);
    free(quick);
    free(shell);
    free(insert);
    return 0;
}