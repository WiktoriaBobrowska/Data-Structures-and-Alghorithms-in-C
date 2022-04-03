typedef struct listNode
{
  int data;
  struct listNode *next;
} node;

void push(node **head, int val); // dodawanie na początek listy
void pushEnd(node **head, int val); // dodawanie na koniec listy
void pop(node **head); // usuwanie pierwszego elementu listy
void popEnd(node **head); // usuwanie ostatniego elementu listy
node* find(node *head, int val); // odszukaj zadany element
void pushBefore(node **head, node *current, int val); // dodaj element przed wskazanym
void pushAfter(node **head, node *current, int val); // dodaj za wskazanym elementem
void removeNode(node **head, node *current); // usuń wskazany element
node* readFromFile(char *fname); // wczytaj zawartość listy z pliku
int saveToFile(node *head, char *fname); // zapisz zawartość listy do pliku

void removeAll_iteratively(node **head, int val); // usuń wszystkie wartości val z listy iteracynie
void removeAll_recursively(node **head, int val); // usuń wszystkie wartości val z listy rekurencyjnie

int findMostCommon(node *head); // znajdź wartość najczęściej występującą na liście

void usunniepodz(node **l, int k); // usuń z listy l wszystkie liczby niepodzielne przez k

void revert_iteratively(void *head); // odwróć listę iteracyjnie
void revert_recursively(void *head); //odwróć listę rekurencyjnie

