# \
CS 3432 -- Computer Architecture\
By: Matthew S Montoya\
Purpose: To practice basic C Programming\
Last Modified: 06 October 2019

tokenizer.o: echo.c tokenizer.c history.c
	gcc echo.c tokenizer.c history.c -o tokenizer.o
clean:
	rm -f *.o