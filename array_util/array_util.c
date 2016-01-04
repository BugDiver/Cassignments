#include "array_util.h"
#include <stdlib.h>

ArrayUtil create(int typeSize , int length){
   ArrayUtil array;
   array.base = calloc(typeSize , length);
   array.typeSize = typeSize;
   array.length = length;
   return array;
}
