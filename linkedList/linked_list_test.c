#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_the_list(LinkedList *list){
	Element *element = list->head;
	while(element){
		free(element);
		element = element->next;
	};
};


void test_create_linked_list(){
	LinkedList list = createList();

	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.length == 0);
	free_the_list(&list);
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
	free_the_list(&list);

}

void test_add_to_list_should_add_a_reference_of_any_type_of_data(){
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
	assert(list.tail->value == &gender);
	assert(*(int *)list.head->value == 1234);
	assert(*(char *)list.tail->value == 'm');
	assert(list.length == 2);

	float result = 87.5;
	int newIncrementedLength = add_to_list(&list ,&result);
	assert(newIncrementedLength == 3);
	assert(list.head->value == &roll_no);
	assert(list.tail->value == &result);
	assert(*(int *)list.head->value == 1234);
	assert(*(float *)list.tail->value == 87.5);
	assert(list.length == 3);
	free_the_list(&list);

};

void test_add_to_list_should_also_add_a_reference_of_user_defined_data_type(){
	LinkedList list  =createList();

	student std1,std2,std3;
	std1.name = "bheema";
	std1.roll_no = 12;
	std2.name = "Bagha";
	std2.roll_no = 00;
	std3.name = "Kachara";
	std3.roll_no = 100;

	add_to_list(&list ,&std1);
	add_to_list(&list ,&std2);
	add_to_list(&list ,&std3);

	assert(list.length == 3);
	assert(list.head->value == &std1);
	assert(list.tail->value == &std3);
	free_the_list(&list);

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
	free_the_list(&list);
}

void test_get_first_element_of_the_list_should_return_address_of_first_added_element_for_char_type(){
	LinkedList list  =createList();

	char char1 = 'a',char2 = 'b',char3 = 'c',char4 = 'd';

	add_to_list(&list ,&char1);
	add_to_list(&list ,&char2);
	add_to_list(&list ,&char3);
	add_to_list(&list ,&char4);

	assert(list.length == 4);

	void *first = get_first_element(list);
	assert(first == &char1);
	assert(*(char *)first == 'a');
	free_the_list(&list);
}
void test_get_first_element_of_the_list_should_return_address_of_first_added_element_for_float_type(){
	LinkedList list  =createList();

	float num1 = 1.5,num2 = 1.4,num3 = 1.7,num4 = 1.9;

	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);

	assert(list.length == 4);

	void *first = get_first_element(list);
	assert(first == &num1);
	assert(*(float *)first == 1.5);
	free_the_list(&list);
}

void test_get_first_element_of_the_list_should_return_address_of_last_added_element_for_user_defined_data_type(){
	LinkedList list  =createList();

	student std1,std2,std3;
	std1.name = "bheema";
	std1.roll_no = 12;
	std2.name = "Bagha";
	std2.roll_no = 00;
	std2.name = "Kachara";
	std2.roll_no = 100;


	add_to_list(&list ,&std1);
	add_to_list(&list ,&std2);
	add_to_list(&list ,&std3);

	assert(list.length == 3);


	student *first = (student *)get_first_element(list);
	assert(first == &std1);
	assert(first->roll_no == 12);
	assert(first->name == "bheema");
	free_the_list(&list);
}

void test_get_last_element_of_the_list_should_return_address_of_last_added_element(){

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
	free_the_list(&list);

}

void test_get_last_element_of_the_list_should_return_address_of_last_added_element_for_char_type(){

	LinkedList list  =createList();

	char char1 = 'a',char2 = 'b',char3 = 'c',char4 = 'd';

	add_to_list(&list ,&char1);
	add_to_list(&list ,&char2);
	add_to_list(&list ,&char3);
	add_to_list(&list ,&char4);

	assert(list.length == 4);

	void *last = get_last_element(list);
	assert(last == &char4);
	assert(*(char *)last == 'd');
	free_the_list(&list);

}

void test_get_last_element_of_the_list_should_return_address_of_last_added_element_for_float_type(){
	LinkedList list  =createList();

	float num1 = 1.5,num2 = 1.4,num3 = 1.7,num4 = 1.5;

	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);

	assert(list.length == 4);


	void *last = get_last_element(list);
	assert(last == &num4);
	assert(*(float *)last == 1.5);
	free_the_list(&list);
}

void test_get_last_element_of_the_list_should_return_address_of_last_added_element_for_user_defined_data_type(){
	LinkedList list  =createList();

	student std1,std2,std3;
	std1.name = "bheema";
	std1.roll_no = 12;
	std2.name = "Bagha";
	std2.roll_no = 00;
	std3.name = "Kachara";
	std3.roll_no = 100;

	add_to_list(&list ,&std1);
	add_to_list(&list ,&std2);
	add_to_list(&list ,&std3);

	assert(list.length == 3);


	student *last = (student *)get_last_element(list);
	assert(last == &std3);
	assert(last->name == "Kachara");
	assert(last->roll_no == 100);
	free_the_list(&list);
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
	free_the_list(&list);

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
	free_the_list(&list);

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
	free_the_list(&list);

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
	free_the_list(&list);

};

void test_asArray_should_copy_all_elements_of_list_into_given_array(){
	LinkedList list  =createList();

	int num1 = 12,num2 = 22,num3 = 32,num4 = 42,num5=52;
	add_to_list(&list ,&num1);
	add_to_list(&list ,&num2);
	add_to_list(&list ,&num3);
	add_to_list(&list ,&num4);
	add_to_list(&list ,&num5);

	void *dest[5];
	int length  =asArray(list, dest, 5);
	assert(length = 5);
	assert(dest[0] == &num1);
	assert(dest[1] == &num2);
	assert(dest[2] == &num3);
	assert(dest[3] == &num4);
	assert(dest[4] == &num5);
	free_the_list(&list);


};

void test_asArray_should_copy_elements_equal_to_the_size_of_array(){
	LinkedList list  =createList();
   int num1 = 12,num2 = 22,num3 = 32,num4 = 45,num5=55;

   add_to_list(&list ,&num1);
   add_to_list(&list ,&num2);
   add_to_list(&list ,&num3);
   add_to_list(&list ,&num4);
   add_to_list(&list ,&num5);

	void *dest[5];
	int length = asArray(list, dest, 3);
	assert(length == 3);
	assert(dest[0] == &num1);
	assert(dest[1] == &num2);
	assert(dest[2] == &num3);
	assert(dest[3] != &num4);
	assert(dest[4] != &num5);
	free_the_list(&list);

};

int isEven(void *hint, void *num){
	if(*(int *)num % 2 == 0)
		return 1;
	return 0;
};

void test_filter_should_return_a_new_linked_list_which_contains_only_matching_elements(){
	LinkedList list = createList();
	int num1 = 1,num2 = 2,num3 = 3,num4 = 4,num5 = 5;

	add_to_list(&list, &num1);
	add_to_list(&list, &num2);
	add_to_list(&list, &num3);
	add_to_list(&list, &num4);
	add_to_list(&list, &num5);

	int hint = 2;
	LinkedList newlist = filter(list, &isEven ,&hint);

	assert(getElementAt(newlist, 0) == &num2);
	assert(getElementAt(newlist, 1) == &num4);
	assert(getElementAt(newlist, 2) == NULL);
	free_the_list(&list);
	free_the_list(&newlist);


}

void test_reverse_should_return_a_new_list_with_all_elements_in_reverse_order(){
	LinkedList list = createList();
	int num1 = 1,num2 = 2,num3 = 3,num4 = 4,num5 = 5;

	add_to_list(&list, &num1);
	add_to_list(&list, &num2);
	add_to_list(&list, &num3);
	add_to_list(&list, &num4);
	add_to_list(&list, &num5);

	LinkedList reversedList = reverse(list);
	assert(getElementAt(reversedList ,0) == &num5);
	assert(getElementAt(reversedList ,1) == &num4);
	assert(getElementAt(reversedList ,2) == &num3);
	assert(getElementAt(reversedList ,3) == &num2);
	assert(getElementAt(reversedList ,4) == &num1);

	assert(getElementAt(list ,0) == &num1);
	assert(getElementAt(list ,1) == &num2);
	assert(getElementAt(list ,2) == &num3);
	assert(getElementAt(list ,3) == &num4);
	assert(getElementAt(list ,4) == &num5);
	free_the_list(&list);

};
void multiplyBy(void* hint, void* sourceItem, void* destinationItem){
	*(int *)destinationItem = *(int *)sourceItem * *(int *)hint;
};

void test_map_should_return_new_list_which_consist_the_all_mapped_elements(){
	LinkedList list = createList();
	int num1 = 1,num2 = 2,num3 = 3,num4 = 4,num5 = 5;

	add_to_list(&list, &num1);
	add_to_list(&list, &num2);
	add_to_list(&list, &num3);
	add_to_list(&list, &num4);
	add_to_list(&list, &num5);

	int multiplier = 10;
	LinkedList mappedList = map(list ,&multiplyBy,&multiplier);

	assert(*(int *)getElementAt(mappedList ,0) == 10);
	assert(*(int *)getElementAt(mappedList ,1) == 20);
	assert(*(int *)getElementAt(mappedList ,2) == 30);
	assert(*(int *)getElementAt(mappedList ,3) == 40);
	assert(*(int *)getElementAt(mappedList ,4) == 50);

	assert(*(int *)getElementAt(list ,0) == 1);
	assert(*(int *)getElementAt(list ,1) == 2);
	assert(*(int *)getElementAt(list ,2) == 3);
	assert(*(int *)getElementAt(list ,3) == 4);
	assert(*(int *)getElementAt(list ,4) == 5);
	free_the_list(&list);
	free_the_list(&mappedList);


};

void* add(void* hint, void* previousItem, void* item){
   *((int *)previousItem) = *((int *)previousItem) + *((int *)item);
   return previousItem;
}

void test_reduce_should_return_the_reduced_value_according_the_reducer_function(){
	LinkedList list = createList();
	int num1 = 1,num2 = 2,num3 = 3,num4 = 4,num5 = 5;

	add_to_list(&list, &num1);
	add_to_list(&list, &num2);
	add_to_list(&list, &num3);
	add_to_list(&list, &num4);
	add_to_list(&list, &num5);

	int init = 10;
	void *result = reduce(list ,add ,NULL ,&init);

	assert(*(int *)result == 25);
	free_the_list(&list);


};
