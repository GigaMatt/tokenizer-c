#include <stdio.h>	//header file

/**
 * .h = HEADER FILES
 * 		CONTAIN METHOD SIGNITURES (.h)
 * 
 *		Similar to "import" in Java
 * 		Similar to "includes" in Java
 * 			i.e. .compareTo(Object e)
 * 
 * .c = C FILE
 * 		THEY CONTAIN DECLARATIONS
 * 			i.e. "This is my logic and how I declare it."
 * 
 * #include = (LITERALLY INCLUDES FILE)
 * 		INCLUDE HEADER FILES INTO OUR .C FILE
 * 		Includes all the packages
 *
 * TO EXECUTE CODE:
 * 		1) gcc program_name.c -o my_program_name
 * 		2) ./my_program_name
*/

int main(){
	void print();
	return 0;
}

void print_hello(){
	printf("Welcome to my first C Program");)
}
