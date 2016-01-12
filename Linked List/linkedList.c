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
		list->first = list->last = node;
	}else{
		list->last->next = node;
		list->last = node;
	}
	list->length++;
	return list->length;
};

void *get_first_element(LinkedList list){
	return list.first->value;
};


void *get_last_element(LinkedList list){
	return list.last->value;
};