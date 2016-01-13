#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


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
	Element *temp = list->head;
	int i=0;
	while(i  != index){
	   temp=temp->next;
	   i++;
	};
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;

	list->length--;
	return temp->value;
};
