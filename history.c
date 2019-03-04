/*
 * CS 154 -- Computer Arch
 * By: Matthew S Montoya
 * Purpose: To practice basic C programming with pointers
 * Last Modified: 3 March 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List *init_history(void)
{
    Item *item = NULL;
    List *linked_list = NULL;

    item = malloc(sizeof(Item));
    linked_list = malloc(sizeof(List));

    linked_list->root = item;
    item->id = 0;
    item->str = "";
    item->next = NULL;

    return linked_list;
}

/* Add a history item to the end of the list.
 List* list - the linked list
 char* str - the string to store
 */
void add_history(List *list, char *str)
{
    Item *current_node = list->root;
    int position = 0;

    if (current_node == NULL)
    {
        current_node = malloc(sizeof(Item));
        current_node->id = 0;
        //Store the String
        current_node->str = str;
        current_node->next = NULL;
    }
    else
    {
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
            position++;
        }
        current_node->next = malloc(sizeof(Item));
        //Store the String
        current_node->next->str = str;
        current_node->next->next = NULL;
        current_node->next->id = position;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
 List* list - the linked list
 int id - the id of the Item to find */
char *get_history(List *list, int id)
{
    Item *current_node = list->root;
    char *node_info = "";

    while (current_node != NULL)
    {
        if (current_node->id == id)
            node_info = current_node->str;
        current_node = current_node->next;
    }
    return node_info;;
}

/* Print the entire contents of the list. */
void print_history(List *list)
{
    //Establish start node
    Item *current_node = list->root;
    while (current_node != NULL)
    {
        printf("%d: %s\n", current_node->id, current_node->str);
        current_node = current_node->next;
    }
}

/* Free all Items and the List. */
void free_history(List *list)
{
    Item *current_node = list->root;
    Item *temp_node;

    while (current_node != NULL)
    {
        temp_node = current_node;
        free(temp_node);
        current_node = current_node->next;
    }
    free(list);
    printf("Your memory is now free!\n");
}
