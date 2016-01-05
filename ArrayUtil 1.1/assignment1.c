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
	util.typeSize = 0;
	util.length = 0;
};

int findIndex(ArrayUtil util, void* element){
	int length = util.length;
	for(int i = 0;i < length;i++){
		if(memcmp((util.base+i),element,util.typeSize) == 0)
			return i;
		return -1;
	};
	return 0;
};






