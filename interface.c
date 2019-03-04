/*
 * CS 154 -- Computer Arch
 * By: Matthew S Montoya
 * Purpose: To practice basic C programming with pointers
 * Last Modified: 3 March 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "tokenizer.c"
#include "history.h"
#include "history.c"

#define MAX 100

int main()
{
	//Print UI for users to input string
	printf("Enter a String to tokenize:\n>");
	char user_input_buffer[MAX];
	fgets(user_input_buffer, MAX, stdin); //Use fgets for safer buffer to prevent buffer overflow security flaw
	printf("Testing User Input: %s\n", user_input_buffer);

	int number_of_words = count_words(user_input_buffer);
	printf("Number of words: %d\n", number_of_words);

	int word_length = string_length(user_input_buffer);
	printf("Length of Word: %d\n", word_length);

	int word_start = find_word_start(user_input_buffer, 0);
	printf("Start of Word: %d\n", word_start);

	int word_end = find_word_end("WORD", 0);
	printf("End of word: %d\n", word_end);

	char **user_tokens = tokenize(user_input_buffer);
	printf("Printing tokens:\n");
	print_tokens(user_tokens);

	printf("Freeing Tokens\n");
	free_tokens(user_tokens);
	printf("Tokens Freed!\n");


	printf("Program Terminated Successfully!\n");

	List *history_list = init_history();
	printf("Initializing History\n");
	add_history(history_list, "Test_1");
	add_history(history_list, "Test_2");
	add_history(history_list, "Test_3");
	add_history(history_list, "Test_4");
	add_history(history_list, "Test_5");
	printf("Printing History\n");
	print_history(history_list);

	printf("Getting History @1\n");
	char *get = get_history(history_list, 2);
	printf("%s\n", get);

	printf("Getting History @5\n");
	get = get_history(history_list, 5);
	printf("%s\n", get);

	printf("Freeing History\n");
	free_history(history_list);
	printf("History Freed!\nProgram Complete!\n");

	return 0;
}
