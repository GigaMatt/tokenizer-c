Lab Project 1: Building a Tokenizer
===================================

## Overview
The objective for this first lab project is to build a tokenizer that
maintains a history. Tokenizing is the process of dividing a string into
tokens by some delimeter (e.g. the string librarys split() function).
Consider tokenizing the string “The cake is a lie!” using the space
character. This would result in: \[“The”, “cake”, “is”, “a”, “lie!”\].



## How To Compile/Run
1. Open the directory to **/ai-tree-searches/test_case_file files/**
2. Execute jar file by typing in: **java -jar AIHW2Lab.jar test_case_size_size.txt BFS**

Alternatively, the _.java_ files may be imported into your IDE and run locally

## Dependancies
1. Compile the *interface.c* program by navigating to the project directory in the terminal and typing **gcc interface.c**
2. Execute the program in the terminal by typing **./a.out**

## Contributions
1.  Hiram Rios: Advising that adding an integer argument to find_word_end() would allow for proper tokenizing.
2.  Matthew Iglesias: Identify the position of the end of a word by checking for spaces or NULL values.
