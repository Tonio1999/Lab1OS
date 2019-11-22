#include <stdio.h>
#include <stdlib.h>
#include "list.h"
list_other *list_alloc() 
{
    list_other *mylist;
    mylist = malloc(sizeof(list_other));
	mylist->head = NULL;
    return mylist;
}
void list_free(list_other *mylist) 
{
    if (mylist == NULL)
    {
        return;
    }
    node_t *current_node = mylist->head;
    node_t *next_node = NULL;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    mylist->head = NULL;
    free(mylist);
}
// Prints list
void list_print(list_other *mylist) 
{
    node_t *current_node = mylist->head;
    node_t *next_node = NULL;
    while (current_node->next != NULL)
    {
        printf("%d -> ", current_node->value);
        next_node = current_node->next;
        current_node = next_node;
    }
	printf("%d", current_node->value);
	printf("\n");
}

// Return length 
int list_length(list_other *mylist) 
{ 
    node_t *current_node = mylist->head;
    int length = 0;
    while (current_node != NULL)
    {
        length ++;
        current_node = current_node->next;
    }
    return length; 
}
void list_add_to_back(list_other *mylist, elem value) 
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    node_t *current_node = mylist->head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}
void list_add_to_front(list_other *mylist, elem value) 
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = mylist->head;
	mylist->head = new_node;
}
void list_add_at_index(list_other *mylist, elem value, int index) 
{
    int count = 1;
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    node_t * current_node = mylist->head;
    node_t* next_node = NULL;
    while (current_node != NULL && count < (index))
    {
        count++;
        next_node = current_node->next;
        current_node = next_node;
    }
    next_node = current_node->next;
    current_node->next = new_node;
    new_node->next = next_node;
}
elem list_remove_from_back(list_other *mylist) 
{ 
    node_t *prev_node = mylist->head;
	node_t *current_node = prev_node->next;
    while (current_node->next != NULL)
    {
		prev_node = current_node;
        current_node = current_node->next;
    }
	prev_node->next = NULL;
    elem value = current_node->value;
    free(current_node);
    return value; 
}
elem list_remove_from_front(list_other *mylist) 
{ 
    node_t *current_node = mylist->head;
    mylist->head = current_node->next;
    elem value = current_node->value;
    free(current_node);
    return value;
}

elem list_remove_at_index(list_other *mylist, int index) 
{ 
    int count = 0;
    node_t *prev_node = mylist->head;
	node_t *current_node = prev_node->next;
    while (current_node->next != NULL && count < (index - 1))
    {
        count++;
		prev_node = current_node;
        current_node = current_node->next;
    }
    node_t *temp = current_node;
    prev_node->next = current_node->next;
    elem value = temp->value;
    free(temp);
    return value;
}
// Checks element
bool list_is_in(list_other *mylist, elem value) 
{
	bool exist;
    node_t *current_node = mylist->head;
    
    while (current_node->next != NULL && !exist)
    {
		if (current_node->value == value)
        {
			exist = true;
		}
        current_node = current_node->next;
    }
    return exist; 
}
// Returns element
elem list_get_elem_at(list_other *mylist, int index) 
{
	int counter = 0;
	elem value = 0;
	node_t *current_node = mylist->head;
    while (current_node->next != NULL && counter < (index))
    {
		counter++;
        current_node = current_node->next;
    }
	if (current_node != NULL)
    {
		value = current_node->value;
	}
	return value; 
}
int list_get_index_of(list_other *mylist, elem value) 
{
	int counter = 0;
	node_t *current_node = mylist->head;
    while (current_node->next != NULL)
    {
		if (current_node->value == value)
        {
			return counter;
		} else 
        {
			counter++;
			current_node = current_node->next;
		}
    }
	return counter; 
}
