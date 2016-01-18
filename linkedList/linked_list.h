typedef struct student{
	char *name;
	int roll_no;
}student;


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


typedef void (*ElementProcessor)(void *);
typedef int(MatchFunc)(void *, void*);
typedef void(ConvertFunc)(void*,void*,void*);
typedef void*(Reducer)(void*, void*, void*);


void intializeList(LinkedList *);

student createStudent();
LinkedList createList();
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int);
void forEach(LinkedList, ElementProcessor);
LinkedList  filter(LinkedList, MatchFunc, void * );
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, ConvertFunc, void *);
void *reduce(LinkedList, Reducer, void *, void *);
