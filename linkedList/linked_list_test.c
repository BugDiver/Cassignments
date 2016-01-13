#include "linked_list.h"
#include <stdio.h>
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

void test_getElementAt_should_return_the_refrence_of_value_at_given_index(){
	LinkedList list  =createList();
	int num1 = 12,num2 = 22,num3 = 32,num4 = 42;
	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);

	void *invalidReference = getElementAt(list ,4);
	assert(invalidReference == NULL);

	void *firstElement = getElementAt(list ,0);
	assert(firstElement == &num1);
	assert(*(int *)firstElement == 12);

	void *secondElement = getElementAt(list ,1);
	assert(secondElement == &num2);
	assert(*(int *)secondElement == 22);


	void *thirdElement = getElementAt(list ,2);
	assert(thirdElement == &num3);
	assert(*(int *)thirdElement == 32);


	void *fourthElement = getElementAt(list ,3);
	assert(fourthElement == &num4);
	assert(*(int *)fourthElement == 42);
};

void test_indexOf_should_return_the_first_index_at_which_this_element_occurs(){
	LinkedList list  =createList();
	int num1 = 12,num2 = 22,num3 = 32,num4 = 42 ,num5=53;
	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);

	int index_of_12 = indexOf(list ,&num1);
	assert(index_of_12 == 0);

	int index_of_22 = indexOf(list ,&num2);
	assert(index_of_22 == 1);

	int index_of_32 = indexOf(list ,&num3);
	assert(index_of_32 == 2);

	int invalidIndex = indexOf(list ,&num5);
	assert(invalidIndex == -1);
}

void test_deleteElementAt_should_delete_the_element_at_give_index_and_return_refrence_of_deleted_value(){
	LinkedList list  =createList();

	int num1 = 12,num2 = 22,num3 = 32,num4 = 42,num5=52;
	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);
	add_to_list(&list ,&num5);


	void *headRefrence = deleteElementAt(&list ,0);
	assert(list.length == 4);
	assert(headRefrence = &num1);
	assert(getElementAt(list ,0) == &num2);

	void *tailRefrence = deleteElementAt(&list ,list.length-1);
	assert(list.length == 3);
	assert(tailRefrence = &num5);
	assert(getElementAt(list ,list.length-1) == &num4);

	void *deletedElement = deleteElementAt(&list ,1);
	assert(list.length == 2);
	assert(deletedElement == &num3);
	assert(*(int *)deletedElement == 32);

	assert(*(int *)getElementAt(list,0) == 22);
	assert(*(int *)getElementAt(list,1) == 42);
};

// int main(){
// 	test_create_linked_list();
// 	test_add_to_list_should_add_a_data_in_list();
// 	test_get_first_element_of_the_list_should_return_address_of_first_added_element();
// 	test_get_last_element_of_the_list_should_return_address_of_first_added_element();
// 	test_for_each_performs_a_given_operation_on_every_element();
// 	test_getElementAt_should_return_the_refrence_of_value_at_given_index();
// 	test_deleteElementAt_should_delete_the_element_at_give_index_and_return_refrence_of_deleted_value();
// 	printf("all okk!!!\n");
// 	return 0;
// }
