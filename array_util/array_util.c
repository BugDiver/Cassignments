#include <stdlib.h>
#include <string.h>
#include "array_util.h"

ArrayUtil create(int typeSize , int length){
   ArrayUtil array;
   array.base = calloc(typeSize , length);
   array.typeSize = typeSize;
   array.length = length;
   return array;
}

int areEqual(ArrayUtil first ,ArrayUtil second){
   int deff = memcmp(first.base ,second.base ,first.length);
   if(first.length == second.length && deff == 0)
      return 1;
   return 0;
}

ArrayUtil resize(ArrayUtil array, int new_size){
   array.base = realloc(array.base ,array.typeSize * new_size);
   array.length = new_size;
   return array;
}

int findIndex(ArrayUtil util ,void *element){
   for (int i = 0; i < util.length; i++) {
      int validation = memcmp(util.base+( i * util.typeSize) , element ,1);
      if(validation ==0 )
         return i;
   }
   return -1;
}

void dispose(ArrayUtil util){
   free(util.base);
}
