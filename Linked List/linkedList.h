typedef struct element{
	void * value;
	struct element * next;
} Element;

typedef struct {
	Element * first;
	Element * last;
	int length;
} LinkedList;

LinkedList createList(void);
int add_to_list(LinkedList *list,void *value);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);