typedef struct element{
	void * value;
	struct element * next;
} Element;

typedef struct {
	Element * first;
	Element * last;
	int length;
} LinkedList;

typedef void(ElementProcessor)(void *);
typedef int MatchFunc(void* hint, void* item);

LinkedList createList(void);
int add_to_list(LinkedList *list,void *value);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList list, ElementProcessor *e);
void * getElementAt(LinkedList list, int value);
int indexOf(LinkedList list, void * value);
void * deleteElementAt(LinkedList *list, int index);
int asArray(LinkedList list, void **array, int maxElements);
LinkedList filter(LinkedList list, MatchFunc match, void * hint);
