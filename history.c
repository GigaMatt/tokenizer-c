/*
 * CS 3432 -- Computer Architecture
 * By: Matthew S Montoya
 * Purpose: To practice basic C Programming
 * Last Modified: 06 October 2019
*/

// Lab, Part 3: Track History
#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
    List* new_list=(List*)malloc(sizeof(List*)*300);
    return new_list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List* list, char* str)
{
    Item* add_item=(Item*)malloc(sizeof(Item)*300);
    add_item->str=str;
    if(list->root==NULL)
    {
        add_item->id=1;
        list->root=add_item;
    }
    else
    {
        Item* history_item = list->root;
        add_item->id=1;
        while(history_item->next!=NULL){
            add_item->id++;
            history_item=history_item->next;
        }
        history_item->next=add_item;
        add_item->id++;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char* get_history(List* list, int id)
{
    Item* history_item=list->root;
    while(history_item->next!=list->root)
    {
        if(history_item->id==id)
            return history_item->str;
        history_item=history_item->next;
    }
    return history_item->str;
}

/* Print the entire contents of the list. */ 
void print_history(List* list)
{
    while(list->root!=NULL)
    {
        printf("History ID:%d, Name:%s\n", list->root->id,list->root->str);
        list->root=list->root->next;
    }
}

/* Free all Items and the List. */
void free_history(List* list)
{
    // while(list->root->next!=NULL)
    // {
    //     free(list->root);
    //     list->root=list->root->next;
    // }
    free(list);
}