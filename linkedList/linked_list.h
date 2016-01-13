typedef void (*ElementProcessor)(void *);

typedef struct element {
	void *value;
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
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int);
void forEach(LinkedList, ElementProcessor);
