#include <stdio.h>
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