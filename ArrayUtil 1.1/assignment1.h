typedef struct{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int(MatchFunc)(void *,void *);
typedef void(ConvertFunc)(void *,void *,void *);
typedef void(OperationFunc)(void*, void*);
typedef void* (ReducerFunc)(void*, void*, void*);

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int areEqual(ArrayUtil a, ArrayUtil b);
void dispose(ArrayUtil util);
int findIndex(ArrayUtil util, void* element);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);