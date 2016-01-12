#include <assert.h>
#include "linkedList.h"
#include <stdio.h>

void test_createList(){
	LinkedList list = createList();
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);
};

void test_addToList(){
	LinkedList list = createList();
	int value1 = 10;
	int result1 = add_to_list(&list,&value1);
	int element1 = *(int *)(list.first->value);
	assert(result1 == 1);
	assert(element1 == 10);
	int value2 = 20;
	int result2 = add_to_list(&list,&value2);
	int element2 = *(int *)(list.last->value);
	assert(result2 == 2);
	assert(element2 == 20);
	int value3 = 30;
	int result3 = add_to_list(&list,&value3);
	int element3 = *(int *)(list.last->value);
	assert(result3 == 3);
	assert(element3 == 30);
};

void test_get_first_element(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int result = *(int *)get_first_element(list);
	assert(result == 10);
};

void test_get_last_element(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int result = *(int *)get_last_element(list);
	assert(result == 10);
	int value1 = 20;
	add_to_list(&list,&value1);
	int result1 = *(int *)get_last_element(list);
	assert(result1 == 20);
	int value2 = 30;
	add_to_list(&list,&value2);
	int result2 = *(int *)get_last_element(list);
	assert(result2 == 30);
};
