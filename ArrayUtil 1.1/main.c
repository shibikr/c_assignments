#include <stdio.h>
#include <assert.h>
#include "assignment1.h"

void createArrayTest(){
	ArrayUtil array1 = create(4,5);
	assert(array1.typeSize == 4);
	assert(array1.length == 5);
};

void resizeArrayTest(){
	ArrayUtil array = create(4,5);
	ArrayUtil array1 = resize(array,10);
	assert(array1.typeSize == 4);
	assert(array1.length == 10);
};

void areEqualTest(){
	ArrayUtil array1 = create(4,5);
	ArrayUtil array2 = create(8,10);
	assert(areEqual(array1,array2) == 0);
	assert(areEqual(array1,array1) == 1);
	assert(areEqual(array2,array2) == 1);
};

void findIndexTest(){
	int value = 1;
	int value1 = 0;
	int value2 = 10;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = value;
	assert(findIndex(array1,&value) == 0);
	assert(findIndex(array1,&value2) == -1);
	assert(findIndex(array1,&value1) == 1);
};

int *isEven(void* hint, void* item){
	int *value = (int *)(item);
	printf("values%d\n",*value);
	if(*value%2 == 0)
		return 1;
	return 0;
};

void findFirstTest(){
	int number = 1;
	void* hint = &number;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = 1;
	((int *)array1.base)[1] = 2;
	((int *)array1.base)[2] = 3;
	((int *)array1.base)[3] = 4;
	((int *)array1.base)[4] = 5;
	// void * result = findFirst(array1,isEven,hint);
	// int *value = (int *)(result);
	// assert(*value == 2);
};

void findLastTest(){
	int number = 1;
	void* hint = &number;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = 1;
	((int *)array1.base)[1] = 2;
	((int *)array1.base)[2] = 3;
	((int *)array1.base)[3] = 4;
	((int *)array1.base)[4] = 5;
	void * result = findLast(array1,isEven,hint);
	int *value = (int *)(result);
	// assert(*value == 4);
	printf("findlast%d\n",*value);

};

void countTest(){
	int number = 1;
	void* hint = &number;
	ArrayUtil array1 = create(4,5);
	((int *)array1.base)[0] = 1;
	((int *)array1.base)[1] = 2;
	((int *)array1.base)[2] = 3;
	((int *)array1.base)[3] = 4;
	((int *)array1.base)[4] = 5;
	// assert(count(array1,isEven,hint) == 2);
};

int main(){
	createArrayTest();
	resizeArrayTest();
	areEqualTest();
	findIndexTest();
	findFirstTest();
	findLastTest();
	countTest();
	return 0;
};