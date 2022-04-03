#include<stdio.h>
#include<limits.h>

int V = 9; //zmienna globalna, ilo�� wierzcho�k�w 
int mindist(int* distance, int* sptSet){

    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (sptSet[i] == 0 && distance[i] <= min) {
            min = distance[i];
            min_index = i;
        }
    }
      
    return min_index;
}

void displayshortestPath(int* parent, int n) {

    if (parent[n] == -1) return;
    displayshortestPath(parent, parent[n]);
    printf("%d ", n);
}

void display(int* distance, int n, int* parent) {
    int source = 0;
    printf("Wierzcholek \t Dystans \t Sciezka \n");

    for (int i = 1; i < V; i++){
        printf("%d ==> %d\t %d\t\t%d", source, i, distance[i], source);
        displayshortestPath(parent, i);
    }
}

void dijkstra(int** graph, int start){

    int distance[V]; //dystans od miejsca startu 
    int sptSet[V]; //1 jesli sptSet[i] jest w najkrotszej sciezce 
    int array[V]; //tablica do przechowywania najkrotszej sciezki

    for (int i = 0; i < V; i++){ //wszystkie dystanse sa nieskonczonoscia
        array[0] = -1;
        distance[i] = INT_MAX;
        sptSet[i] = 0;
    }

    distance[start] = 0; //dystans ze startu do startu to 0

    for (int temp = 1; temp < V; temp++) {
        int mins = mindist(distance, sptSet);
        sptSet[mins] = 1; //aktualny wierzcholek poznany 

        for (int v = 0; v < V; v++) {
            if (sptSet[v] == 0 && graph[mins][v] && distance[mins] + graph[mins][v] < distance[v]) {
                array[v] = mins;
                distance[v] = distance[mins] + graph[mins][v];
            }
        }

    }
}

void read_and_display_Graph(char* fname){
    int i, j;
    int **graph = calloc(V, sizeof(int*));
    for (int i = 0; i < V; i++) graph[i] = malloc(V, sizeof(int));


    FILE* file=fopen(fname, "r");
    if (file == NULL) printf("Cannot open the file");

    for(i = 0; i < V; i++) {
      for(j = 0; j < V; j++){
       if (!fscanf(file, "%d", &graph[i][j])) 
           break;
        printf("%d \n",graph[i][j]);
      }
  }
  fclose(file);
}
