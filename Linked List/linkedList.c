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


