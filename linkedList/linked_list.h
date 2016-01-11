typedef struct element {
	int value;
	struct element *next;
	struct element *prev;
} Element;


typedef struct linked_list {
	Element *head;
	Element *tail;
	int length;
}LinkedList;

void intializeList(LinkedList *);
LinkedList createList();