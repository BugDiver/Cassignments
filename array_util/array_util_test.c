#include "array_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



void test_create_array_util_for_int(int *num){
   ArrayUtil scores = create(4 ,5);
   assert(scores.typeSize == 4);
   assert(scores.length == 5);
   int *a  = (int *)scores.base;
   a[0] = 95;
   assert(a[0] == 95);
   dispose(scores);
   (*num)++;
}

void test_create_array_util_for_float(int *num){
   ArrayUtil weight = create(8,5);
   assert(weight.typeSize == 8);
   assert(weight.length == 5);
   float *b = (float *)weight.base;
   b[0] = 10.5;
   assert(b[0] == 10.5);
   dispose(weight);
   (*num)++;
}


void test_create_array_util_for_char(int *num){
   ArrayUtil name = create(1,5);
   assert(name.typeSize == 1);
   assert(name.length == 5);

   char *c = (char *)name.base;
   c[0] = 'h';
   c[1] = 'e';
   c[2] = 'l';
   c[3] = 'l';
   c[4] = 'o';

   assert(c[0] == 'h');
   assert(strcmp("hello" ,c) == 0);

   dispose(name);
   (*num)++;
}

void test_are_equal_for_int_type_array_util(int *num){
   ArrayUtil score1 = create(4 ,5);
   ArrayUtil score2 = create(4 ,5);
   int *s1 = (int *)score1.base;
   int *s2 = (int *)score2.base;
   s1[0] = 92;
   s2[0] = 80;

   int deff = areEqual(score1 ,score2);
   assert(deff == 0);
   (*num)++;

   dispose(score1);
   dispose(score2);
}

void test_are_equal_for_char_type_array_util(int *num){
   ArrayUtil f_name = create(1,5);
   char *f = (char *)f_name.base;
   f[0] = 'h';
   f[1] = 'e';
   f[2] = 'l';
   f[3] = 'l';
   f[4] = 'o';

   ArrayUtil s_name = create(1,5);
   char *s = (char *)s_name.base;
   s[0] = 'h';
   s[1] = 'e';
   s[2] = 'l';
   s[3] = 'l';
   s[4] = 'o';

   int validation = areEqual(f_name , s_name);
   assert(validation == 1);
   (*num)++;

   dispose(f_name);
   dispose(s_name);
}

void test_resize_array_util_for_int_type(int *num){
   ArrayUtil scores = create(4,5);
   int *s  = (int *)scores.base;
   s[0] = 92; s[1] = 90; s[2] = 45; s[3] = 76; s[4] = 54;
   scores = resize(scores ,3);
   assert(scores.length == 3);
   (*num)++;
   dispose(scores);
}

void test_resize_array_util_for_char_type(int *num){
   ArrayUtil name = create(1,5);
   char *s  = (char *)name.base;
   s[0] = 'v'; s[1] = 'i'; s[2] = 'n'; s[3] = 'a'; s[4] = 'y';
   name = resize(name ,3);
   assert(name.length == 3);
   (*num)++;
   dispose(name);
}

void test_find_index_for_int_type(int *num){
   ArrayUtil scores = create(4,5);
   int *s  = (int *)scores.base;
   s[0] = 92; s[1] = 90; s[2] = 45; s[3] = 76; s[4] = 54;
   int x = 45, y = 92 ,z = 76, a = 123;
   int index_of_x = findIndex(scores , &x);
   int index_of_y = findIndex(scores , &y);
   int index_of_z = findIndex(scores , &z);
   int index_of_a = findIndex(scores , &a);
   assert(index_of_x == 2);
   assert(index_of_y == 0);
   assert(index_of_z == 3);
   assert(index_of_a == -1);
   (*num)++;
   dispose(scores);
}

void test_find_index_for_char_type(int *num){
   ArrayUtil name = create(4,5);
   int *s  = (int *)name.base;
   s[0] = 'h'; s[1] = 'e'; s[2] = 'l'; s[3] = 'l'; s[4] = 'o';

   char x = 'h', y = 'l' ,z = 'l' ,  a = 'n';

   int index_of_x = findIndex(name , &x);
   int index_of_y = findIndex(name , &y);
   int index_of_z = findIndex(name , &z);
   int index_of_a = findIndex(name , &a);

   assert(index_of_x == 0);
   assert(index_of_y == 2);
   assert(index_of_z == 2);
   assert(index_of_a == -1);

   (*num)++;
   dispose(name);
}

int divisibleBy(void *num1 ,void *num2){
   int divider = *(int *)num1;
   int dividend = *(int *)num2;
   if(dividend % divider == 0)
      return 1;
   return 0;
}

void test_find_first_for_int_type(int * num){
   ArrayUtil integers = create(sizeof(int),5);
   int *s  = (int *)integers.base;
   s[0] = 15, s[1] = 2, s[2] = 3, s[3] = 4, s[4] = 5;
   int divider1 =2;
   int f_num = *(int *)findFirst(integers ,divisibleBy , &divider1);
   assert(f_num == 2);
   int divider2 = 5;
   int first_multiple_of_5 = *(int *)findFirst(integers ,divisibleBy , &divider2);
   assert(first_multiple_of_5 = 15);
   (*num)++;
};

char to_lower(char character){
   if(character  >= 'A' && character <='Z')
      return character + 32;
   return character;
}

int is_vowel(void *hint ,void *my_char){
   char c = *(char *)my_char;
   c = to_lower(c);
   if(c == 'a' || c== 'e'|| c== 'i'|| c== 'o'|| c== 'u')
      return 1;
   return 0;
}


void test_find_first_for_char_type(int * num){
   ArrayUtil name = create(sizeof(char),5);
   char *s  = (char *)name.base;
   s[0] ='h', s[1] = 'e', s[2] = 'l', s[3] = 'l', s[4] = 'o';
   char a = 'a';
   char f_vowel = *(char *)findFirst(name ,is_vowel , &a);
   assert(f_vowel == 'e');
   (*num)++;
}

void test_find_last_for_int_type(int * num){
   ArrayUtil integers = create(sizeof(int),5);
   int *s  = (int *)integers.base;
   s[0] = 15, s[1] = 2, s[2] = 3, s[3] = 4, s[4] = 5;
   int divider1 =2;
   int l_num = *(int *)findLast(integers ,divisibleBy , &divider1);
   assert(l_num == 4);
   int divider2 = 5;
   int last_multiple_of_5 = *(int *)findLast(integers ,divisibleBy , &divider2);
   assert(last_multiple_of_5 = 5);
   (*num)++;
};

void test_find_last_for_char_type(int * num){
   ArrayUtil name = create(sizeof(char),5);
   char *n  = (char *)name.base;
   n[0] ='h', n[1] = 'e', n[2] = 'l', n[3] = 'l', n[4] = 'o';
   char a = 'a';
   char l_vowel = *(char *)findLast(name ,is_vowel , &a);
   assert(l_vowel == 'o');
   (*num)++;
}
void test_count_for_int_type(int *num){
   ArrayUtil integers = create(sizeof(int),5);
   int *s  = (int *)integers.base;
   s[0] = 15, s[1] = 2, s[2] = 6, s[3] = 4, s[4] = 5;
   int divider1 = 2;
   int no_of_even_numbers = count(integers ,divisibleBy , &divider1);
   assert(no_of_even_numbers == 3);
   (*num)++;

};

void test_count_for_char_type(int * num){
   ArrayUtil name = create(sizeof(char),5);
   char *n  = (char *)name.base;
   n[0] ='h', n[1] = 'e', n[2] = 'l', n[3] = 'l', n[4] = 'o';
   char a = 'a';
   int count_of_vowel = count(name ,is_vowel , &a);
   assert(count_of_vowel == 2);
   (*num)++;
}

int is_even(void *hint, void *item){
  int *num = (int *)item;
  if(*num % 2 == 0)
    return 1;
  return 0;
};

int is_greater_than(void *hint ,void *num){
   int num1 = *(int *)hint;
   int num2 = *(int *)num;
   if(num2 > num1)
      return 1;
   return 0;
}

void test_filter_array_util_for_int_type(int *num){
   ArrayUtil scores = create(sizeof(int) ,6);
   int *s = (int *)scores.base;
   s[0] = 92; s[1] = 45; s[2] = 90; s[3] = 76; s[4] = 54, s[5] = 73;
   int hint = 75;
   ArrayUtil destination = create(sizeof(int),4);
   int no_of_distinction = filter(scores ,&is_greater_than ,&hint, destination.base ,destination.length);
   assert(no_of_distinction == 3);
   (*num)++;
}



void test_filter_should_add_elements_into_given_array(int * num){
   ArrayUtil a = create(4,5);
   int * list_array = (int *)(a.base);
   list_array[0] = 12;
   list_array[1] = 25;
   list_array[2] = 34;
   list_array[3] = 45;
   list_array[4] = 5;
   ArrayUtil dest = create(4, 10);
   assert(filter(a, &is_even, NULL, dest.base, 10) == 2);

   int **d = ((int **)dest.base);
   assert(*d[0] == 12);
   assert(*d[1] == 34);
   (*num)++;

};
void test_filter_should_add_the_addresses_of_elements_into_given_array(int * num){
   ArrayUtil a = create(1,5);
   char * list_array = (char *)(a.base);
   list_array[0] = 'a';
   list_array[1] = 'b';
   list_array[2] = 'c';
   list_array[3] = 'd';
   list_array[4] = 'e';

   ArrayUtil dest = create(1, 5);
   assert(filter(a, &is_vowel, NULL, dest.base, 10) == 2);

   char **d = (char **)dest.base;
   assert(*d[0] == 'a');
   assert(*d[1] == 'e');
   (*num)++;
};

void increment_by(void *hint, void *sourceItem, void *destinationItem){
   int *num = (int *)sourceItem;
   int *increment = (int *)hint;
   *num = *num + *increment;
   *((int *)destinationItem) = *num;
};

void test_map_should_copy_converted_element_in_destination(int * num){
   ArrayUtil source = create(sizeof(int),5);
   int * list = (int *)(source.base);
   list[0] = 12;
   list[1] = 2;
   list[2] = 3;
   list[3] = 4;
   list[4] = 5;

   ArrayUtil destination = create(4,5);
   int increment = 2;

   map(source, destination, &increment_by, &increment);
   int *d = (int *)destination.base;

   assert(d[0] == 14);
   assert(d[1] == 4);
   assert(d[2] == 5);
   assert(d[3] == 6);
   assert(d[4] == 7);
   (*num)++;
};

void rot_13(void *hint, void *sourceItem, void *destinationItem){
   char *c = (char *)sourceItem;
   if(to_lower(*c) < 'n')
      *c = *c + 13;
   else
      *c = *c - 13;
   *((char *)destinationItem) = *c;
}

void test_map_should_cpy_converted_element_in_destination_for_char(int * num){
   ArrayUtil name = create(sizeof(char) ,5);
   char *n = (char *)name.base;
   n[0] = 'h',n[1] = 'e',n[2] = 'l',n[3] = 'l',n[4] = 'o';

   ArrayUtil destination = create(sizeof(char),5);
   map(name, destination, &rot_13, NULL);

   char *d = (char *)destination.base;
   assert(d[0] == 'u');
   assert(d[1] == 'r');
   assert(d[2] == 'y');
   assert(d[3] == 'y');
   assert(d[4] == 'b');
   assert(strcmp(d ,"uryyb") == 0);
   (*num)++;
}

void decrement_by(void *hint ,void *item){
   *((int *)item) = *((int *)item) - *((int *)hint);
}

void test_forEach_executes_operation_for_each_int_element(int * num){
  ArrayUtil source = create(4,5);
  int * list_array = (int *)(source.base);
  list_array[0] = 12;
  list_array[1] = 32;
  list_array[2] = 33;
  list_array[3] = 42;
  list_array[4] = 54;

  int hint = 10;
  forEach(source, &decrement_by, &hint);

  assert(((int *)source.base)[0] == 2);
  assert(((int *)source.base)[1] == 22);
  assert(((int *)source.base)[2] == 23);
  assert(((int *)source.base)[3] == 32);
  assert(((int *)source.base)[4] == 44);
  (*num)++;
};

void to_upper(void* hint, void* item){
   if(*(char *)item >='a' && *(char *)item <='z')
      *((char *)item) = *((char *)item) - 32;
}

void test_forEach_executes_operation_for_each_char_element(int *num){
  ArrayUtil source = create(1,5);
  char * list_array = (char *)(source.base);
  list_array[0] = 'a';
  list_array[1] = 'b';
  list_array[2] = 'c';
  list_array[3] = 'd';
  list_array[4] = 'e';


  forEach(source, &to_upper, NULL);
  assert(((char *)source.base)[0] == 'A');
  assert(((char *)source.base)[1] == 'B');
  assert(((char *)source.base)[2] == 'C');
  assert(((char *)source.base)[3] == 'D');
  assert(((char *)source.base)[4] == 'E');
  (*num)++;
};


void* add(void* hint, void* previousItem, void* item){
   *((int *)previousItem) = *((int *)previousItem) + *((int *)item);
   return previousItem;
}

void test_reduce_reduces_the_list_and_gives_a_value(int * num){
   ArrayUtil list = create(4,5);
   int * list_array = (int *)(list.base);
   list_array[0] = 1,list_array[1] = 2,list_array[2] = 3,list_array[3] = 4,list_array[4] = 5;
   int init = 10;
   int result = *(int *)reduce(list ,add ,NULL ,&init);
   assert(result == 25);
   (*num)++;
}
int main() {
   int no_of_passing_test = 0;

   test_create_array_util_for_int(&no_of_passing_test);
   test_create_array_util_for_float(&no_of_passing_test);
   test_create_array_util_for_char(&no_of_passing_test);

   test_are_equal_for_char_type_array_util(&no_of_passing_test);
   test_are_equal_for_int_type_array_util(&no_of_passing_test);

   test_resize_array_util_for_int_type(&no_of_passing_test);
   test_resize_array_util_for_char_type(&no_of_passing_test);

   test_find_index_for_int_type(&no_of_passing_test);
   test_find_index_for_char_type(&no_of_passing_test);

   test_find_first_for_int_type(&no_of_passing_test);
   test_find_first_for_char_type(&no_of_passing_test);

   test_find_last_for_int_type(&no_of_passing_test);
   test_find_last_for_char_type(&no_of_passing_test);

   test_count_for_int_type(&no_of_passing_test);
   test_count_for_char_type(&no_of_passing_test);

   test_filter_array_util_for_int_type(&no_of_passing_test);
   test_filter_should_add_elements_into_given_array(&no_of_passing_test);
   test_filter_should_add_the_addresses_of_elements_into_given_array(&no_of_passing_test);

   test_map_should_copy_converted_element_in_destination(&no_of_passing_test);
   test_map_should_cpy_converted_element_in_destination_for_char(&no_of_passing_test);

   test_forEach_executes_operation_for_each_int_element(&no_of_passing_test);
   test_forEach_executes_operation_for_each_char_element(&no_of_passing_test);

   test_reduce_reduces_the_list_and_gives_a_value(&no_of_passing_test);

   printf("no of passing tests ==>> %d\n", no_of_passing_test);
   return 0;
}
