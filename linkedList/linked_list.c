#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

student createStudent(){
	student std;
	std.name = NULL;
	std.roll_no = 0;
	return std;
}

void intializeList(LinkedList *list){
	list->head = list->tail = NULL;
	list->length = 0;
}

LinkedList createList(){
	LinkedList list;
	intializeList(&list);
	return list;
}

int add_to_list(LinkedList *list,void *data){
	Element *element = (Element *)malloc(sizeof(Element));
	element->value = data;
	element->next = NULL;
	element->prev = NULL;
	if(list->length==0){
		list->head = list->tail = element;
	}
	else{
		element->prev = list->tail;
		list->tail->next = element;
		list->tail = element;
	}
	list->length++;
	return list->length;
};


void *get_first_element(LinkedList list){
	return list.head->value;
};

void *get_last_element(LinkedList list){
	return list.tail->value;
};

void forEach(LinkedList list, ElementProcessor operater){
	Element *element = list.head;
	while (element != NULL) {
		operater(element->value);
		element = element->next;
	}
}

void * getElementAt(LinkedList list, int index){
	if(index > list.length-1)
		return NULL;
	Element *temp = list.head;
	int i=0;
	while(i  != index){
	   temp=temp->next;
	   i++;
	}
	return temp->value;
};

int indexOf(LinkedList list, void *data){
	Element *temp = list.head;
	int i=0;
	while(i  < list.length){
		if(temp->value == data)
			return i;
	   temp=temp->next;
	   i++;
	};
	return -1;
}

void * deleteElementAt(LinkedList *list, int index){
	if(index >= list->length){
		return NULL;
	}
	Element *temp = list->head;
	int i=0;
	while(i  != index){
	   temp=temp->next;
	   i++;
	};
	if(temp->prev==NULL){
		temp->next->prev = NULL;
		list->head = temp->next;
	}else if(temp->next==NULL){
		temp->prev->next = NULL;
		list->tail = temp->prev;
	}
	else{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	}
	list->length--;
	return temp->value;
};

int asArray(LinkedList list, void **array, int max){
	Element *element = list.head;
	int i=0;
	for (i = 0; i < max && i < list.length; i++) {
		array[i] =  element->value;
		element = element->next;
	}
	return i;
};

LinkedList filter(LinkedList list, MatchFunc *match ,void *hint){
  LinkedList newList = createList();
  Element *element = list.head;
  while(element != NULL){
    if(match(NULL, element->value))
      add_to_list(&newList, element -> value);
    element = element -> next;
  };
  return newList;
};

LinkedList reverse(LinkedList list){
	LinkedList reversedList = createList();
	Element *current = list.tail;
	while (current !=  NULL){
       add_to_list(&reversedList ,current->value);
		 current = current->prev;
   }
	return reversedList;
}

LinkedList map(LinkedList list, ConvertFunc convert, void *hint){
	Element *element = list.head;
	LinkedList mappedList = createList();
	void *dest;
	while(element != NULL){
		dest = malloc(sizeof(void *));
		convert(hint,element->value ,dest);
		add_to_list(&mappedList,dest);
		element = element->next;
	}
	return mappedList;
};

void* reduce(LinkedList list,Reducer reducer, void *hint, void *initialValue){
   Element *element = list.head;
   while(element != NULL){
      initialValue  = reducer(hint ,initialValue ,element->value);
      element = element->next;
   }
   return initialValue;
};
