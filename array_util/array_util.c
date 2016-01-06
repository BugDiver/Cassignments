#include <stdlib.h>
#include <string.h>
#include "array_util.h"

ArrayUtil create(int typeSize , int length){
   ArrayUtil array;
   array.base = calloc(typeSize , length);
   array.typeSize = typeSize;
   array.length = length;
   return array;
};

int areEqual(ArrayUtil first ,ArrayUtil second){
   int deff = memcmp(first.base ,second.base ,first.length);
   if(first.length == second.length && deff == 0)
      return 1;
   return 0;
};

ArrayUtil resize(ArrayUtil array, int new_size){
   array.base = realloc(array.base ,array.typeSize * new_size);
   array.length = new_size;
   return array;
};

int findIndex(ArrayUtil util ,void *element){
   for (int i = 0; i < util.length; i++) {
      int validation = memcmp(util.base+( i * util.typeSize) , element ,1);
      if(validation ==0 )
         return i;
   }
   return -1;
};

void dispose(ArrayUtil util){
   free(util.base);
};

void* findFirst(ArrayUtil list,MatchFunc* match, void* hint){
   for (int i = 0; i < list.length; i++) {
      if(match( hint,list.base+(i*list.typeSize)) == 1)
         return list.base +(i*list.typeSize);
   }
   return 0;
};

void* findLast(ArrayUtil list,MatchFunc* match, void* hint){
   for (int i = 0; i < list.length; i++) {
      if(match( hint,list.base+((list.length-i-1)*list.typeSize)) == 1)
         return list.base+((list.length-i-1)*list.typeSize);
   }
   return 0;
};

int count(ArrayUtil list,MatchFunc* match, void* hint){
   int count = 0;
   for (int i = 0; i < list.length; i++) {
      if(match( hint,list.base+(i*list.typeSize)) == 1)
         count++;
   }
   return count;
}

int filter(ArrayUtil util, MatchFunc *match, void *hint, void **destination, int maxItems){
   void *base = util.base;
   int count = 0;
   for(int i = 0; i < util.length && count < maxItems; i++){
    if(match(hint, base)){
      destination[count] = base;
      count++;
    };
    base = base + util.typeSize;
   };
   return count;
};
