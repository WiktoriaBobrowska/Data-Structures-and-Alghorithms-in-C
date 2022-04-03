typedef struct listNode
{
  int data;
  struct listNode* next;
} linkedListNode;

typedef linkedListNode* node;

void push(node* head, int value); // dodawanie na pocz�tek listy
void pushEnd(node* head, int value); // dodawanie na koniec listy
int pop(node* head); // usuwanie pierwszego elementu listy
void popEnd(node* head); // usuwanie ostatniego elementu listy
node* find(node *head, int value); // odszukaj zadany element
void pushBefore(node current, int val); // dodaj element przed wskazanym
void pushAfter(node current, int val); // dodaj za wskazanym elementem
void removeNode(node* head, node current); // usu� wskazany element
node readFromFile(char* fname); // wczytaj zawarto�� listy z pliku
int saveToFile(node head, char* fname); // zapisz zawarto�� listy do pliku

void diffList(node* a, node b); // usu� z listy a wszystkie wyst�pienia element�w z listy b