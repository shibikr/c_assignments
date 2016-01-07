typedef struct{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int(MatchFunc)(void *,void *);

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int areEqual(ArrayUtil a, ArrayUtil b);
void dispose(ArrayUtil util);
int findIndex(ArrayUtil util, void* element);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );


