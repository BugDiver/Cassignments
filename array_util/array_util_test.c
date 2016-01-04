#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
   c[0] = 'h';
   c[1] = 'e';
   c[2] = 'l';
   c[3] = 'l';
   c[4] = 'o';

   assert(c[0] == 'h');
   assert(strcmp("hello" ,c) == 0);

   free(c);
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
   free(s1);
   free(s2);
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

   free(f);
   free(s);
}
int main() {
   int no_of_passing_test = 0;
   test_create_array_util_for_int(&no_of_passing_test);
   test_create_array_util_for_float(&no_of_passing_test);
   test_create_array_util_for_char(&no_of_passing_test);
   test_are_equal_for_char_type_array_util(&no_of_passing_test);
   test_are_equal_for_int_type_array_util(&no_of_passing_test);

   printf("no of passing tests ==>> %d\n", no_of_passing_test);
   return 0;
}
