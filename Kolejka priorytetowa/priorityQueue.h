typedef struct priorityQueue
{
    int data;
    int priority;
    struct priorityQueue* next;

} priorityQueueNode;

typedef priorityQueueNode* node;

void addElement(node* head, int val, int priority); // dodawanie nowego elementu
node getHighestPriority(node* head); // pobieranie elementu z najwyższym priorytetem i jego usuwanie z kolejki
void changeElementPriority(node* head, int val, int priority); // znajdowanie elementu o konktretnej wartości i zmiana jego priorytetu na wskazany

//dodatkowe/pomocnicze
void createElement(node* head, int val, int priority);
void pop(node* head);