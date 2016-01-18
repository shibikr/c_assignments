#include <assert.h>
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_createList(){
	LinkedList list = createList();
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);
};

void test_addToList_adds_integers(){
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

void test_addToList_adds_chars(){
	LinkedList list = createList();
	char value = 'H';
	int result1 = add_to_list(&list,&value);
	char element1 = *(char *)(list.first->value);
	assert(result1 == 1);
	assert(element1 == 'H');
	char value2 = 'a';
	int result2 = add_to_list(&list,&value2);
	char element2 = *(char *)(list.last->value);
	assert(result2 == 2);
	assert(element2 == 'a');
	char value3 = 'i';
	int result3 = add_to_list(&list,&value3);
	char element3 = *(char *)(list.last->value);
	assert(result3 == 3);
	assert(element3 == 'i');
};

void test_addToList_adds_string(){
	LinkedList list = createList();
	char value1[] = "C";
	int result1 = add_to_list(&list,&value1);
	char *element1 = (char *)(list.first->value);
	assert(result1 == 1);
	assert(element1 == value1);
	char value2[] = "is";
	int result2 = add_to_list(&list,&value2);
	char *element2 = (char *)(list.last->value);
	assert(result2 == 2);
	assert(element2 == value2);
	char value3[] = "simple";
	int result3 = add_to_list(&list,&value3);
	char *element3 = (char *)(list.last->value);
	assert(result3 == 3);
	assert(element3 == value3);
};

void test_addToList_adds_doubles(){
	LinkedList list = createList();
	double value1 = 10.1;
	int result1 = add_to_list(&list,&value1);
	double element1 = *(double *)(list.first->value);
	assert(result1 == 1);
	assert(element1 == 10.1);
	double value2 = 20.2;
	int result2 = add_to_list(&list,&value2);
	double element2 = *(double *)(list.last->value);
	assert(result2 == 2);
	assert(element2 == 20.2);
	double value3 = 30.3;
	int result3 = add_to_list(&list,&value3);
	double element3 = *(double *)(list.last->value);
	assert(result3 == 3);
	assert(element3 == 30.3);
};

void test_addToList_adds_float(){
	LinkedList list = createList();
	float value1 = 10.1;
	int result1 = add_to_list(&list,&value1);
	float element1 = *(float *)(list.first->value);
	assert(result1 == 1);
	assert(element1 == value1);
	float value2 = 20.2;
	int result2 = add_to_list(&list,&value2);
	float element2 = *(float *)(list.last->value);
	assert(result2 == 2);
	assert(element2 == value2);
	float value3 = 30.3;
	int result3 = add_to_list(&list,&value3);
	float element3 = *(float *)(list.last->value);
	assert(result3 == 3);
	assert(element3 == value3);
};

void test_get_first_element_should_give_integer(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int result = *(int *)get_first_element(list);
	assert(result == 10);
};

void test_get_first_element_should_give_char(){
	LinkedList list = createList();
	char value = 'a';
	add_to_list(&list,&value);
	char result = *(char *)get_first_element(list);
	assert(result == 'a');
};

void test_get_first_element_should_give_string(){
	LinkedList list = createList();
	char value[] = "shibi";
	add_to_list(&list,&value);
	char *result = (char *)get_first_element(list);
	assert(result == value);
};

void test_get_first_element_should_give_double(){
	LinkedList list = createList();
	double value = 10.1;
	add_to_list(&list,&value);
	double result = *(double *)get_first_element(list);
	assert(result == 10.1);
};

void test_get_first_element_should_give_float(){
	LinkedList list = createList();
	float value = 10.1;
	add_to_list(&list,&value);
	float result = *(float *)get_first_element(list);
	assert(result == value);
};

void test_get_last_element_should_return_integer(){
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

void test_get_last_element_should_return_char(){
	LinkedList list = createList();
	char value = 'a';
	add_to_list(&list,&value);
	char result = *(char *)get_last_element(list);
	assert(result == 'a');
	char value1 = 'b';
	add_to_list(&list,&value1);
	char result1 = *(char *)get_last_element(list);
	assert(result1 == 'b');
	char value2 = 'c';
	add_to_list(&list,&value2);
	char result2 = *(char *)get_last_element(list);
	assert(result2 == 'c');
};

void test_get_last_element_should_return_string(){
	LinkedList list = createList();
	char value[] = "hello";
	add_to_list(&list,&value);
	char *result = (char *)get_last_element(list);
	assert(result == value);
	char value1[] = "hai";
	add_to_list(&list,&value1);
	char *result1 = (char *)get_last_element(list);
	assert(result1 == value1);
	char value2[] = "how";
	add_to_list(&list,&value2);
	char *result2 = (char *)get_last_element(list);
	assert(result2 == value2);
};

void test_get_last_element_should_return_double(){
	LinkedList list = createList();
	double value = 10.1;
	add_to_list(&list,&value);
	double result = *(double *)get_last_element(list);
	assert(result == 10.1);
	double value1 = 20.2;
	add_to_list(&list,&value1);
	double result1 = *(double *)get_last_element(list);
	assert(result1 == 20.2);
	double value2 = 30.3;
	add_to_list(&list,&value2);
	double result2 = *(double *)get_last_element(list);
	assert(result2 == 30.3);
};

void test_get_last_element_should_return_float(){
	LinkedList list = createList();
	float value = 10.1;
	add_to_list(&list,&value);
	float result = *(float *)get_last_element(list);
	assert(result == value);
	float value1 = 20.2;
	add_to_list(&list,&value1);
	float result1 = *(float *)get_last_element(list);
	assert(result1 == value1);
	float value2 = 30.3;
	add_to_list(&list,&value2);
	float result2 = *(float *)get_last_element(list);
	assert(result2 == value2);
};

void incrementInteger(void *value){
	*(int*)value = *((int *)value)+1;
};

void test_forEach_increments_each_element_in_the_linkedlist_for_integers(){
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
	forEach(list,&incrementInteger);
	assert(*(int *)list.first->value == 11);
	assert(*(int *)list.last->value == 51);
};

void incrementFloat(void *value){
	*(float*)value = *((float *)value)+1;
};

void test_forEach_increments_each_element_in_the_linkedlist_for_float(){
	LinkedList list = createList();
	float value = 10.1;
	add_to_list(&list,&value);
	float value1 = 20.2;
	add_to_list(&list,&value1);
	float value2 = 30.3;
	add_to_list(&list,&value2);
	float value3 = 40.4;
	add_to_list(&list,&value3);
	float value4 = 50.5;
	add_to_list(&list,&value4);
	forEach(list,&incrementFloat);
	float result = *(float *)list.first->value;
	assert(result == result);
	float result1 = *(float *)list.last->value;
	assert(result1 == result1);
};

void square(void *value){
	*(int*)value *= *((int *)value);
};

void test_forEach_square_each_element_in_the_linkedlist(){
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
	forEach(list,&square);
	assert(*(int *)list.first->value == 100);
	assert(*(int *)list.last->value == 2500);
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

void test_indexOf_should_give_NULL_if_the_value_given_is_not_present(){
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

void test_deleteElementAt_should_return_NULL_if_the_index_is_greater_than_list_length(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);

	assert(deleteElementAt(&list, 4) == NULL);
};

void test_deleteElementAt_should_return_NULL_if_the_index_is_less_than_zero(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);

	assert(deleteElementAt(&list, -1) == NULL);
};

void test_deleteElementAt_should_return_deleted_value(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);

	assert(deleteElementAt(&list, 0) == &value);
	assert(list.first->value == &value1);
	assert(list.length == 3);
};

void test_deleteElementAt_should_return_last_element(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);

	assert(deleteElementAt(&list, 3) == &value3);
	assert(list.last->value == &value2);
	assert(list.length == 3);
};

void test_deleteElementAt_should_return_the_element_which_deleted(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);

	assert(deleteElementAt(&list, 2) == &value2);
	assert(list.length == 3);
};

void test_asArray_should_give_new_length(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	void *array = calloc(5,4);
	assert(asArray(list,array,5) == 4);	
};

void test_asArray_should_change_values_in_the_array(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	void *array = calloc(5,4);
	asArray(list,array,5);
	int arr[] = {10,20,30,40};
	for(int i = 0;i<4;i++){
		assert(**(int**)array == arr[i]);
		array+=8;
	};
};

int isDivisible(void *hint,void *item){
	if(*(int*)item % *(int*)hint == 0)
		return 1;
	return 0;
};

void test_filter_for_isDivisible_by_3(){
	int hint = 3;
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	LinkedList newList = filter(list,isDivisible,&hint);
	assert(newList.first->value == &value2);
};

void test_filter_for_isDivisible_by_6(){
	int hint = 6;
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 12;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 42;
	add_to_list(&list,&value3);
	LinkedList newList = filter(list,isDivisible,&hint);
	assert(newList.first->value == &value1);
	newList.first = newList.first->next;
	assert(newList.first->value == &value2);
	newList.first = newList.first->next;
	assert(newList.first->value == &value3);
};

void test_reverse_gives_the_reversed_list(){
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 12;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 42;
	add_to_list(&list,&value3);
	LinkedList newList = reverse(list);
	assert(*(int*)newList.first->value == 42);
	newList.first = newList.first->next;
	assert(*(int*)newList.first->value == 30);
	newList.first = newList.first->next;
	assert(*(int*)newList.first->value == 12);
	assert(*(int*)newList.last->value == 10);
};

void multiply(void* hint, void* sourceItem, void* destinationItem){
	int *dest = malloc(sizeof(int));
	*dest = *(int *)sourceItem * *(int *)hint;
	memcpy(destinationItem,&dest,8);
};

void test_map_for_multiply_with_2(){
	int hint = 2;
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	LinkedList newList = map(list,multiply,&hint);
	assert(*(int*)newList.first->value == 20);
	newList.first = newList.first->next;
	assert(*(int*)newList.first->value == 40);
	newList.first = newList.first->next;
	assert(*(int*)newList.first->value == 60);
	newList.first = newList.first->next;
	assert(*(int*)newList.first->value == 80);
};

void* add(void* hint, void* previousItem, void* item){
	*(int*)previousItem += *(int*)item;
	return previousItem;
};

void test_reduce_for_addition_of_integers(){
	int hint = 2;
	int intialValue = 0;
	LinkedList list = createList();
	int value = 10;
	add_to_list(&list,&value);
	int value1 = 20;
	add_to_list(&list,&value1);
	int value2 = 30;
	add_to_list(&list,&value2);
	int value3 = 40;
	add_to_list(&list,&value3);
	assert(*(int*)reduce(list,add,&hint,&intialValue) == 100);
};
