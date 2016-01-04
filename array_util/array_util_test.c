#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "array_util.h"

void test_create_array_util_for_int(int *num){
   ArrayUtil scores = create(4 ,5);
   assert(scores.typeSize == 4);
   assert(scores.length == 5);
   int *a  = (int *)scores.base;
   a[0] = 95;
   assert(a[0] == 95);
   free(a);
   (*num)++;
}

void test_create_array_util_for_float(int *num){
   ArrayUtil weight = create(8,5);
   assert(weight.typeSize == 8);
   assert(weight.length == 5);
   float *b = (float *)weight.base;
   b[0] = 10.5;
   assert(b[0] == 10.5);
   free(b);
   (*num)++;
}


void test_create_array_util_for_char(int *num){
   ArrayUtil name = create(1,5);
   assert(name.typeSize == 1);
   assert(name.length == 5);
   char *c = (char *)name.base;
   c[0] = 'c';
   assert(c[0] == 'c');
   free(c);
   (*num)++;
}


int main() {
   int no_of_passing_test = 0;
   test_create_array_util_for_int(&no_of_passing_test);
   test_create_array_util_for_float(&no_of_passing_test);
   test_create_array_util_for_char(&no_of_passing_test);


   printf("no of passing tests ==>> %d\n", no_of_passing_test);
   return 0;
}
