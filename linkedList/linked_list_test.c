#include "linked_list.h"
#include <assert.h>

void test_create_linked_list(void){
	LinkedList list = createList();

	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.length == 0);
}

