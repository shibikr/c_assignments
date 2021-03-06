#include <stdio.h>
#include <assert.h>
#include "assignment1.h"

void test_createArray(){
	ArrayUtil array1 = create(4,5);
	assert(array1.typeSize == 4);
	assert(array1.length == 5);
};

void test_resizeArray(){
	ArrayUtil array = create(4,5);
	ArrayUtil array1 = resize(array,10);
	assert(array1.typeSize == 4);
	assert(array1.length == 10);
};

void test_areEqual(){
	ArrayUtil array1 = create(4,5);
	ArrayUtil array2 = create(8,10);
	assert(areEqual(array1,array2) == 0);
	assert(areEqual(array1,array1) == 1);
	assert(areEqual(array2,array2) == 1);
};

void test_findIndex(){
	int value = 1;
	int value1 = 0;
	int value2 = 10;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = value;
	assert(findIndex(array1,&value) == 0);
	assert(findIndex(array1,&value2) == -1);
	assert(findIndex(array1,&value1) == 1);
};

int isEven(void* hint, void* item){
	int *value = (int *)(item);
	if(*value%2 == 0)
		return 1;
	return 0;
};

int isDivisible(void* hint, void* item){
	int *value = (int*) item;
	int *divisor = (int*) hint;
	if(*value%*divisor == 0)
		return 1;
	return 0;
};

void test_findFirst(){
	int number = 3;
	void* hint = &number;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = 1;
	((int *)array1.base)[1] = 2;
	((int *)array1.base)[2] = 3;
	((int *)array1.base)[3] = 4;
	((int *)array1.base)[4] = 5;
	void * result = findFirst(array1,isEven,hint);
	int *value = (int *)(result);
	void * result1 = findFirst(array1,isDivisible,hint);
	int *value1 = (int *)(result1);
	assert(*value == 2);
	assert(*value1 == 3);
};

void test_findLast(){
	int number = 3;
	void* hint = &number;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = 1;
	((int *)array1.base)[1] = 2;
	((int *)array1.base)[2] = 3;
	((int *)array1.base)[3] = 4;
	((int *)array1.base)[4] = 5;
	void * result = findLast(array1,isEven,hint);
	int *value = (int *)(result);
	void * result1 = findFirst(array1,isDivisible,hint);
	int *value1 = (int *)(result1);
	assert(*value == 4);
	assert(*value1 == 3);
};

void test_count(){
	int number = 3;
	void* hint = &number;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = 1;
	((int *)array1.base)[1] = 2;
	((int *)array1.base)[2] = 3;
	((int *)array1.base)[3] = 4;
	((int *)array1.base)[4] = 5;
	assert(count(array1,isEven,hint) == 2);
	assert(count(array1,isDivisible,hint) == 1);
};

void test_filter(){
	int number = 3;
	void* hint = &number;
	ArrayUtil source = create(4,5);
	((int *)source.base)[0] = 1;
	((int *)source.base)[1] = 2;
	((int *)source.base)[2] = 3;
	((int *)source.base)[3] = 4;
	((int *)source.base)[4] = 5;
	ArrayUtil destination = create(8,5);
	int **dest = destination.base;
	assert(filter(source,isDivisible,hint,destination.base,5) == 1);
	assert(filter(source,isEven,hint,destination.base,5) == 2);
};

void multiply(void* hint, void* sourceItem, void* destinationItem){
	int *multiplier = (int *) hint;
	int *value = (int *) sourceItem;
	int result = (*value) * (*multiplier);
	int *dest = (int *)destinationItem;
	*dest = result;  
};

void test_map(){
	int number = 3;
	void* hint = &number;
	ArrayUtil source = create(4,5);
	((int *)source.base)[0] = 1;
	((int *)source.base)[1] = 2;
	((int *)source.base)[2] = 3;
	((int *)source.base)[3] = 4;
	((int *)source.base)[4] = 5;
	ArrayUtil destination = create(4,5);
	map(source,destination,multiply,hint);
	int *base = (int *)destination.base;
	assert(*(base) == 3);
	assert(*(base+1) == 6);
	assert(*(base+2) == 9);
	assert(*(base+3) == 12);
	assert(*(base+4) == 15);
};

void multiplyForEach(void* hint, void* sourceItem){
	int *multiplier = (int *) hint;
	int *value = (int *) sourceItem;
	int result = (*value) * (*multiplier);
	*value = result;  
};

void test_forEach(){
	int number = 2;
	void* hint = &number;
	ArrayUtil source = create(4,5);
	((int *)source.base)[0] = 1;
	((int *)source.base)[1] = 2;
	((int *)source.base)[2] = 3;
	((int *)source.base)[3] = 4;
	((int *)source.base)[4] = 5;
	forEach(source,multiplyForEach,hint);
	int *base = (int *)source.base;
	assert(*(base) == 2);
	assert(*(base+1) == 4);
	assert(*(base+2) == 6);
	assert(*(base+3) == 8);
	assert(*(base+4) == 10);
};

void *add(void *hint,void *previousItem, void* item){
	int *prev = (int *) previousItem;
	int *current = (int *) item;
	*prev = *prev + *current;
	void *result = prev;
	return result;
};

void test_reduce(){
	int initial = 0;
	void * initialValue = &initial;
	int hintValue = 2;
	void *hint = &hintValue;
	ArrayUtil source = create(4,5);
	((int *)source.base)[0] = 1;
	((int *)source.base)[1] = 2;
	((int *)source.base)[2] = 3;
	((int *)source.base)[3] = 4;
	((int *)source.base)[4] = 5;
	void * result = reduce(source, add, hint, initialValue);
	int *value = (int *)(result);
	assert(*value == 15);
};
