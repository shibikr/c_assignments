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

void increment(void *value){
	*(int*)value = *((int *)value)+1;
};

void test_forEach_increments_each_element_in_the_linkedlist(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	int value4 = 50;
	add_to_list(&list,&value4);
	forEach(list,&increment);
	assert(*(int *)list.first->value == 11);
	assert(*(int *)list.last->value == 51);
};

void test_getElementAt_gives_value_of_the_index_given(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	int value4 = 50;
	int element = *(int*)(getElementAt(list,2));
	assert(element == 30);
};

void test_getElementAt_gives_NULL_when_the_index_given_is_not_in_list(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	int value4 = 50;
	assert(getElementAt(list,6) == NULL);
};

void test_indexOf_gives_index_of_the_value_given_if_it_is_present(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	int value4 = 50;
	assert(indexOf(list,&value3) == 3);
};

void test_indexOf_gives_NULL_if_the_value_given_is_not_present(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	int value4 = 50;
	int value5 = 60;
	assert(indexOf(list,&value5) == -1);
};