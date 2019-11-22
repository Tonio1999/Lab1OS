#include <stdbool.h>
typedef int elem;
struct node 
{
	elem value;
	struct node *next;
};
typedef struct node node_t;
struct list 
{
	node_t *head;
};
typedef struct list list_other;
list_other *list_alloc();
void list_free(list_other *mylist);
void list_print(list_other *mylist);
int list_length(list_other *mylist);
void list_add_to_back(list_other *mylist, elem value);
void list_add_to_front(list_other *mylist, elem value);
void list_add_at_index(list_other *mylist, elem value, int index);
elem list_remove_from_back(list_other *mylist);
elem list_remove_from_front(list_other *mylist);
elem list_remove_at_index(list_other *mylist, int index);
bool list_is_in(list_other *mylist, elem value);
elem list_get_elem_at(list_other *mylist, int index);
int list_get_index_of(list_other *mylist, elem value);
