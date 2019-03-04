/*
 * CS 154 -- Computer Arch
 * By: Matthew S Montoya
 * Purpose: To practice basic C programming with pointers
 * Last Modified: 3 March 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Counts the number of characters in the string argument.*/
int string_length(char *str)
{
	int str_length = 0;
	int string_position = 0;
	while (str[string_position] != '\0')
	{
		str_length++;
		string_position++; //Increment the number of strings
	}
	return str_length;
}

/* Evaluates if the character c is an acceptable character for
   a token. Acceptable characters include any alphanumeric or
   special character. Unacceptable characters include any
   whitespace or control characters.
   Returns 0 if not, 1 if yes. */
char is_valid_character(char c)
{
	if (c >= 33 & c <= 122) //Utilize ASCII table values to determine if c is a valid char
		return '1';
	else
		return '0';
}

/* Finds the next word in the string. 
   For example, given an input of "  my cake" the function
   should return "my cake". */
int find_word_start(char *str, int start_position)
{ //CONTRIBUTION: Changed to int && added int to argument for tokenizing: Hiram Rios
	int word_start_location = 0;
	for (int position = start_position; str[position] != '\0'; position++)
	{ //Compiler is screaming about the NULL value; NULL represents integer
		if (str[position] == ' ')
		{
			word_start_location = position + 1;
			break;
		}
	}
	return word_start_location; //Return string without space
}

/* Finds the end of current word.
   For example, given an input of "my cake" the function
   should return " cake". */
int find_word_end(char *str, int start_position)
{ //CONTRIBUTION: Changed to int && added int to argument for tokenizing: Hiram Rios
	int word_end_location = 0;
	for (int position = start_position; str[position] != '\0'; position++)
	{ //CONTRIBUTION: MATT: Identify position with space or NULL value
		if (str[position + 1] == ' ')
		{
			word_end_location = position;
			break;
		}
		if (str[position + 1] == '\0')
		{
			word_end_location = position;
			break;
		}
	}
	return word_end_location; //Return from the beginning		\/ now that I changed the code, im not so sure this works
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
    int word_count = 0;
    for(int i=0; str[i]; i++){
        if((i ==0) && (str[i] != ' ')) {     
            word_count++; 
        }
        if((str[i] == ' ') && (str[i+1] != ' ') && (str[i + 1] != '\0')) {
            word_count++;
        }
    }
    return word_count;
}

/* Tokenizes the string argument into an array of tokens.
   For example, "hello world string" would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" */
char **tokenize(char *str)
{
    int num_of_word = count_words(str), word_start = 0, word_end = 0;
		int word_length;
    int character_position;

		//Store word in char array
    char **word = malloc(num_of_word * sizeof(char*)+1);
		//Allocate space for the word
	  word[num_of_word] = (char*) malloc(sizeof(char));
    *word[num_of_word] = '\0';
  
    for(int i=0; i<num_of_word; i++){
        if(i == 0){
            word_end = find_word_end(str, word_start);
						//Malloc the current word
            word[i] = (char*) malloc((word_end + 2) * sizeof(char));
						//Put word into position of array
            for(int j = 0; j < word_end+1; j++){
	            word[i][j] = str[j];
            }
            word[i][word_end+1] = '\0';
        }
        else{
            word_start = find_word_start(str, word_end);
            character_position = word_start;
            word_end = find_word_end(str, word_start);
            word_length = (word_end-word_start);
            word[i] = (char*) malloc((word_length+2)*sizeof(char));
            for(int j=0; j<word_length+1; j++){
	            word[i][j] = str[character_position];
	            character_position++;
            }
            word[i][word_end + 1] = '\0';
        }
    }
  return word;
}

/* Prints all tokens. 
 * Remember (**) refers to a char array of tokens
*/
void print_tokens(char **tokens)
{
    int position = 0;
    while(*tokens[position] != '\0'){
        printf("%s\n", tokens[position]);
        position++;
    }
}

/* Frees all tokens and the array containing the tokens.
 * Remember (**) refers to a char array of tokens
*/
void free_tokens(char **tokens)
{
	int position = 0;
	while (*tokens[position] != '\0')
	{
		free(*tokens);
		position++;
	}
}
