#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

LinkedList createList(void){
	LinkedList list;
	list.first = list.last = NULL;
	list.length = 0;
	return list;
};

int add_to_list(LinkedList *list,void *value){
	Element *node;
	node = (Element *)malloc(sizeof(Element));
	node->value = value;
	node->next = NULL;
	if(list->length == 0){
		list->first = node;
	}else{
		list->last->next = node;
	};
	list->last = node;
	list->length++;
	return list->length;
};

void *get_first_element(LinkedList list){
	return list.first->value;
};

void *get_last_element(LinkedList list){
	return list.last->value;
};

void forEach(LinkedList list, ElementProcessor *increment ){
	while(list.first != NULL){
		increment(list.first->value);
		list.first = list.first->next;
	};
};

void * getElementAt(LinkedList list, int value){
	for(int i = 0;i<list.length;i++){
		if(i == value){
			return list.first->value;
		}
		list.first = list.first->next;
	};
	return NULL;
};

int indexOf(LinkedList list, void * value){
	for(int i = 0;i<list.length;i++){
		if(list.first->value == value){
			return i;
		}
		list.first = list.first->next;
	};
	return -1;
};

void * deleteElementAt(LinkedList *list, int index){
	void *value;
	Element *ptr;
	if(index == 0){
		value = list->first->value;
		ptr = list->first;
		list->first = ptr->next;
		free(ptr);
		list->length--;
		return value;
	}else if(index >= 0 && index < list->length) {
		for(int i = 0;i < list->length;i++){
			if(i == list->length-2 && index == list->length-1){
				value = list->first->next->value;
				ptr = list->first->next;;
				list->last = list->first;
				list->first->next = NULL;
				free(ptr);
				list->length--;
				return value;
			}else if(index-1 == i){
				value = list->first->next->value;
				ptr = list->first->next;;
				list->first->next = ptr->next;
				free(ptr);
				list->length--;
				return value;
			}
			list->first = list->first->next;
		}
	}
	return NULL;
};

int asArray(LinkedList list, void **array, int maxElements){
	int length = (maxElements > list.length) ? list.length:maxElements;
	for(int i = 0;i<length;i++){
		array[i] = list.first->value;
		list.first = list.first->next;
	};
	return length;
};

LinkedList filter(LinkedList list, MatchFunc match, void *hint ){
	LinkedList newList = createList();
	for(int i = 0;i<list.length;i++){
		if(match(hint,list.first->value) == 1)
			add_to_list(&newList,list.first->value);
		list.first = list.first->next;
	};
	return newList;
};

LinkedList reverse(LinkedList list){
	LinkedList reverseList = createList();
	for(int i = list.length-1; i>=0 ;i--){
		add_to_list(&reverseList,getElementAt(list,i));
	}
	return reverseList;	
};

LinkedList map(LinkedList list, ConvertFunc convert, void *hint ){
	LinkedList newList = createList();
	for(int i = 0;i<list.length;i++){
		add_to_list(&newList,NULL);
		convert(hint,list.first->value,&(newList.last->value));
		list.first = list.first->next;
	};
	return newList;
};

void* reduce(LinkedList list, Reducer reduceFun, void *hint, void *initialValue){
	void *previousValue;
	if(initialValue == NULL)
		previousValue = list.first->value;
	previousValue = initialValue;
	while(list.first!=NULL){
		previousValue = reduceFun(hint,previousValue,list.first->value);
		list.first = list.first->next;
	};
	return previousValue;
};
