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
