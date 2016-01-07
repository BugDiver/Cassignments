typedef int(MatchFunc)(void*, void*);
typedef void(ConvertFunc)(void *, void *, void *);
typedef void(OperationFunc)(void* , void* );
typedef void*(ReducerFunc)(void* , void* , void* );
typedef struct array_util{
   void *base;
   int typeSize;
   int length;
}ArrayUtil;


ArrayUtil create(int ,int);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void *);
void dispose(ArrayUtil);
void* findFirst(ArrayUtil ,MatchFunc *, void *);
void* findLast(ArrayUtil ,MatchFunc *, void *);
int count(ArrayUtil, MatchFunc*, void* );
int filter(ArrayUtil, MatchFunc*, void*, void**, int);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil, OperationFunc* , void* );
void* reduce(ArrayUtil, ReducerFunc* , void* , void* );
