/* The main test file for the Operating Systems C-Linked List for storing strings*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main() 
{

    /*Testing creation and addition.*/
    printf("**********************************************************\n");
    printf("Testing the creation and the addition of elements to the list.\n\n");
    list* test1;
    test1 = create_list();

    printf("**********************************************************\n");
    printf("List created. Adding the strings: John, Hi, Martin, Ricky.\n\n");
    add_to_list(test1, "Barry");
    add_to_list(test1, "Jerry");
    add_to_list(test1, "Walter");
    add_to_list(test1, "Thomas");

    printf("**********************************************************\n");
    printf("Elements added to the list. Now Printing the list.\n\n");
    print_list(test1);
    printf("\n");

    /* Testing the removal */
    printf("**********************************************************\n");
    printf("Call the remove function. Should remove the 1st element of the list.\n\n");
    char* deleted_str;
    deleted_str = remove_from_list(test1);

    printf("**********************************************************\n");
    printf("Element Removed. Now printing the updated list and deleted node.\n\n");
    print_list(test1);
    printf("\nDeleted String: %s\n\n", deleted_str);

    /* Second removal. */
    printf("**********************************************************\n");
    printf("Called the remove function. Should remove the 1st element of the list.\n\n");
    deleted_str = remove_from_list(test1);

    printf("**********************************************************\n");
    printf("Element Removed. Now printing the updated list and deleted node.\n\n");
    print_list(test1);
    printf("\nDeleted String: %s\n\n", deleted_str);

    /* Testing the flush of list function*/
    printf("**********************************************************\n");
    printf("Called the flush function. Should create an empty list.\n");
    flush_list(test1);
    if ((test1->head == NULL) && (test1->tail == NULL)) 
    {
        printf("The list flush was successful.\n\n");
    }

    /* Testing the free list function*/
    printf("**********************************************************\n");
    printf("Called the free list. Should the list and everything in it.\n\n");
    free_list(test1);

    printf("Program Testing has ended. Hope you enjoyed. :) \n");


    return 0;

}
