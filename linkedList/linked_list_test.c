#include "linked_list.h"
#include <assert.h>

void test_create_linked_list(){

	LinkedList list = createList();

	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.length == 0);
};

void test_add_to_list_should_add_a_data_in_list(){
	LinkedList list  =createList();

	int roll_no = 1234;
	int newLength = add_to_list(&list ,&roll_no);

	assert(newLength == 1);
	assert(list.head->value == &roll_no);
	assert(list.tail->value == &roll_no);
	assert(*(int *)list.tail->value == 1234);
	assert(list.length == 1);

	int gender = 'm';
	int incrementedLength = add_to_list(&list ,&gender);

	assert(incrementedLength == 2);
	assert(list.head->value == &roll_no);
	assert(*(int *)list.head->value == 1234);
	assert(list.tail->value == &gender);
	assert(*(char *)list.tail->value == 'm');
	assert(list.length == 2);	

}

void test_get_first_element_of_the_list_should_return_address_of_first_added_element(){
	
	LinkedList list  =createList();

	int num1 = 12,num2 = 22,num3 = 32,num4 = 42;

	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);

	assert(list.length == 4);

	void *first = get_first_element(list);
	assert(first == &num1);
	assert(*(int *)first == num1);

}


void test_get_last_element_of_the_list_should_return_address_of_first_added_element(){
	
	LinkedList list  =createList();

	int num1 = 12,num2 = 22,num3 = 32,num4 = 42;

	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);

	assert(list.length == 4);

	void *last = get_last_element(list);
	assert(last == &num4);
	assert(*(int *)last == num4);

}


void increment(void *value){
	(*(int *)value)++;
	
};

void test_for_each_performs_a_given_operation_on_every_element(){
	LinkedList list  =createList();

	int num1 = 12,num2 = 22,num3 = 32,num4 = 42;

	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);

	forEach(list,&increment);

	assert(*(int *)get_first_element(list) == 13);
	assert(*(int *)get_last_element(list) == 43);

	forEach(list,&increment);

	assert(*(int *)get_first_element(list) == 14);
	assert(*(int *)get_last_element(list) == 44);

}









