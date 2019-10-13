/*
 * CS 3432 -- Computer Architecture
 * By: Matthew S Montoya
 * Purpose: To practice basic C Programming
 * Last Modified: 06 October 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"                          // For testing the tokenizer.c file
#include "history.h"
#define MAX 300

int count = 0;

/**
 * MILESTONE 1: BUILD A SIMPLE UI
 */
int main()
{
    printf("Enter a String. Enter '0' to exit\n> ");
    char user_input_buffer[MAX];
    fgets(user_input_buffer, MAX, stdin);       // Instructor reccomendation: Use fgets()
    count++;
    
    // Terminate Program on command
    if(user_input_buffer[0]=='0'){
        printf("Terminating Program...\n");
        return 0;
    }

    // Evaluate String Input
    printf("\nInput: %s\n", user_input_buffer);
    char* start_word = find_word_start(user_input_buffer);
    char* end_word = find_word_end(user_input_buffer);
    printf("Number of words: %d\n", count_words(user_input_buffer));
    printf("Length of Word: %d\n", string_length(user_input_buffer));
    printf("Start of Word: %s\n", start_word);
    printf("End of word: %s\n", end_word);
    int word_length = count_words(user_input_buffer);
    char **user_tokens = (char**) malloc(word_length);  // Consider sending in a pointer
    user_tokens = tokenize(user_input_buffer);
    print_tokens(user_tokens);
    
    List *history_list = init_history();
	printf("Initializing History\n");
    char *test_1 = "Test_1";
    char *test_2 = "Test_2";
	add_history(history_list, test_1);
	add_history(history_list, test_2);

	printf("Printing History\n");
	print_history(history_list);

	printf("Getting History @1\n");
	char *get_1 = get_history(history_list, 0);
	printf("%s\n", get_1);

    printf("Getting History @2\n");
	char *get_2 = get_history(history_list, 1);
	printf("%s\n", get_2);

    // Loop Until Terminated by User
    if(user_input_buffer[0]!='0'){
        int loop = main();
    }
	printf("Freeing History...\n");
	free_history(history_list);
	printf("History Freed!\nProgram Complete!\n");

    return 0;
}