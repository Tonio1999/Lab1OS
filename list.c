/* Source File for Operating Systems C-Linked List for storing strings*/

#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Adds the string to node*/
node* create_node(char* item) 
{
    node* new_node = malloc(sizeof(node));
    int len = strlen(item);
    char* new_str = malloc(len + 1);
    strncpy(new_str, item, len);
    new_node->data = new_str;
    new_node->next = NULL;
    return new_node;
}

/* Allocates and initializes a new list */
list* create_list() 
{
    list* lst = malloc(sizeof(list));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}

/* Adds item to end of the list. This function allocates a
* new buffer and copies the string from item (use malloc,
* strlen, and strncpy; or try strdup).
* Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item) 
{
    node* curr = ll->head;
    node* new_node = create_node(item);
    if (ll->head == NULL) {
        ll->head = new_node;
        ll->tail = new_node;
        return 0;
    }
    else 
    {
        node* temp = malloc(sizeof(node)); // temp for the last item in the list
        temp = ll->tail;
        temp->next =  new_node;
        ll->tail = new_node;
        return 0;
    }
    return 1;
}

/* Removes the string from the front of the list and
* returns a pointer to it. The caller is expected to free
* the string returned when finished with it. */
char* remove_from_list(list* ll) 
{
    node* temp_remov = malloc(sizeof(node));
    temp_remov = ll->head;
    char* deleted_str = malloc(sizeof(temp_remov->data));

    if (ll->head == ll->tail)
    {
        deleted_str = temp_remov->data;
        free(ll->tail);
        ll->head = NULL;
        ll->tail = NULL;
    }
    else 
    {
        deleted_str = temp_remov->data;
        ll->head = temp_remov->next;
        free(temp_remov);
    }
    return deleted_str;
}

/* Prints every string in the list, with a new line
* character at the end of each string */
void print_list(list *ll)
{
    node *curr = malloc(sizeof(node));
    curr = ll -> head;
    printf("Starting the print list function\n");
    while (curr != NULL)
    {
        printf("\t%s \n", curr -> data);
        curr = curr -> next;
    }
    printf("Ended the print list function\n");
    return;
}

/* Flushes (clears) the entire list and re-initializes the
* list. The passed pointer ll should still point to a
* valid, empty list when this function returns. Any memory
* allocated to store items in the list should be freed. */
void flush_list(list* ll)
{
    node *curr = malloc(sizeof(node));
    curr = ll -> head;
    node *next = malloc(sizeof(node));
    while (curr != NULL )
    {
        next = curr -> next;
        free(curr);
        curr = next;
    }
    free(next);
    free(ll);
    ll = create_list();
    return;
}

/* De-allocates all data for the list. Ensure all memory
* allocated for this list is freed, including any
* allocated strings and the list itself. */
void free_list(list *ll)
{
    node *curr = malloc(sizeof(node));
    curr = ll -> head;
    node *next = malloc(sizeof(node));
    while (curr != NULL )
    {
        next = curr -> next;
        free(curr->data);
        free(curr);
        curr = next;
    }
    free(next);
    free(ll);
    free(curr);
    return;

}
