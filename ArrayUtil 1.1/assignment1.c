#include "assignment1.h"
#include <stdlib.h>
#include <string.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil util; 
	util.base = calloc(length,typeSize);
	util.typeSize = typeSize;
	util.length = length;
	return util;
};

ArrayUtil resize(ArrayUtil util, int length){
	util.base = realloc(util.base,length*(util.typeSize)); ;
	util.length = length;
	return util;
};

int areEqual(ArrayUtil a, ArrayUtil b){
	int check = memcmp(a.base,b.base,a.typeSize);
	if(check == 0 && a.length == b.length && a.typeSize == b.typeSize)
		return 1;
	return 0;
};

void dispose(ArrayUtil util){
	free(util.base);
};

int findIndex(ArrayUtil util, void* element){
	int length = util.length;
	for(int i = 0;i < length;i++){
		if(memcmp(util.base,element,util.typeSize) == 0)
			return i;
		util.base+=util.typeSize;
	};
	return -1;
};

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int *value = (int *) (util.base);
	for(int i = 0;i < util.length;i++){
		if(match(hint,&value[i]) == 1 )
			return (&value[i]);
	};
	return NULL;
};

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	int *value = (int *) (util.base);
	for(int i = (util.length-1);i >= 0 ;i--){
		if(match(hint,&value[i]) == 1 )
			return (&value[i]);
	};
	return NULL;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int *value = (int *) (util.base);
	int count = 0;
	for(int i = 0;i < util.length;i++){
		if(match(hint,&value[i]) == 1 )
			count++;
	};
	return count;
};




