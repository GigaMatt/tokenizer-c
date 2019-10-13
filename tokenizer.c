/*
 * CS 3432 -- Computer Architecture
 * By: Matthew S Montoya
 * Purpose: To practice basic C Programming
 * Last Modified: 06 October 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/**
 * MILESTONE 2: WORKING WITH STRINGS
 */

/** Counts the number of characters in the string argument.
 * NOTE: WE HAVE A CHAR* NAMED STR
*/
int string_length(char *str)
{
    int num_chars = 0;
    int pos = 0;
    while(str[pos])
    {
        num_chars++;
        pos++;
    }
    return num_chars-1;
}

/* Evaluates if the character c is an acceptable character for
   a token. Acceptable characters include any alphanumeric or
   special character. Unacceptable characters include any
   whitespace or control characters.
   Returns 0 if not, 1 if yes. */
char is_valid_character(char c)
{
    // Special Characters: characters with octal codes 000 through 037, and 177
    if (c >= 34 & c <= 126)
        return 1;
    else
        return 0;
}

/* Finds the next word in the string. 
   For example, given an input of "  my cake" the function
   should return "my cake". */
char *find_word_start(char *str)
{
    if (count_words(str) > 0)
    {                                // Determine if more than zero words exist
        char *temp_char_array = str; // Duplicate array for checking
        while (*temp_char_array)
        {
            if ((is_valid_character(temp_char_array[0])) == 1)
            {                           // DANIEL (INSTRUCTOR): C BOOLEANS ARE COMPRISED OF INTS
                return temp_char_array; // Return the next words, beginning with valid chars
            }
            *temp_char_array++;
        }
    }
    return str; // Return original array if no valid chars exist
}

/* Finds the end of current word.
   For example, given an input of "my cake" the function
   should return " cake". */
char *find_word_end(char *str)
{
    while (is_valid_character(*str))
    {
        str++;
        if (*str == 32)
        {
            return str; // Return the end of current word
        }
    }
    return "0"; // Return original array if no valid chars exist
}

/* Counts the number of words in the string argument. */
int count_words(char* str)
{
    int pos_1 = 0, pos_2 = 0, num_words = 1;
    while(is_valid_character(str[pos_2])==0)
    {
        pos_1++;
        pos_2++;
    }
    pos_2 = string_length(str);

    while(is_valid_character(str[pos_2])== 0)
    {
        pos_2--;
    }

    // Find the difference to separate out the words
    while(pos_1 < pos_2)
    {
        if((is_valid_character(str[pos_1])==0) && (is_valid_character(str[pos_1+1])==1))
            num_words++;
        pos_1++;
    }
    return num_words;
}

/* Tokenizes the string argument into an array of tokens.
   For example, "hello world string" would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" */
char **tokenize(char *str)
{
    // Daniel (Instructor): mallloc() necessary for this lab
    int pos = 0, word_length = count_words(str);
    char** tokens = (char**) malloc((word_length+1) * sizeof(char*));

    while(pos<word_length)
    {
        str = find_word_start(str);
        char* tokenized_word = token_copy(str);
        str = find_word_end(str);
        tokens[pos] = tokenized_word;

        pos++;
    }
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
    int pos = 0;
    while (tokens[pos])
    { // Loop through the string & individually print the chars
        printf("[%d] = %s\n", pos, tokens[pos]);
        pos++;
    }
}

/* Frees all tokens and the array containing the tokens. */
void free_tokens(char **tokens)
{
    // Daniel (Instructor): "free" is a keyword. Don't reinvent the wheel
    int pos = 0;
    while (tokens[pos])
    {
        // Loop through the string & individually free the chars
        free(tokens[pos]);
        pos++;
    }
    free(tokens);
}

/* Copy Parameter & return */
char *token_copy(char *tokens)
{
    char *str_copy_1 = tokens;
    int word_length = 0, pos = 0;  // Placeholder for cycling through array
    while(str_copy_1[pos])
    {
        if(is_valid_character(str_copy_1[pos]) == 1)
            word_length++;
        else
            break;

        pos++;
    }

    char* str_copy_2 = (char*) malloc(word_length + 1);
    pos = 0;                        // Reset variable so we can continue using variable
    while(pos<word_length)
    {
        str_copy_2[pos] = str_copy_1[pos];
        pos++;
    }
    str_copy_2[pos] = '\0';         // Tell the array we are at the end
    return str_copy_2;
}