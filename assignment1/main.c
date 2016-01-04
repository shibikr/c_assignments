#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "assignment1.h"

ArrayUtil create(int typeSize, int length){
	ArrayUtil *base = (ArrayUtil *)calloc(length,typeSize);
	return *base;
};

int main(){
	printf("%d\n",create(4,10));
	return 0;
};