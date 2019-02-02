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
	void print_hello();
	void arithmetic_variables();
	return 0;
}

void print_hello(){
	//		\n necessary b.c. C has no default "new line" value (i.e. print() vs println() in Java)
	printf("Welcome to my first C Program\n");
}

/**
 * SIMPLE VARIABLE DECLARATIONS AND WHILE-LOOPING
 */ 
void arithmetic_variables(){
	//Multiple declarations similar like in Java
	int faren, celc;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	faren=lower;
	
	//Calculate celc values given faren values
	printf("Degrees F\tDegrees C")

	while(faren <= upper){
		celc = 5*(faren-32)/9;
		printf("%d\t%d\n", faren, celc);
		faren+= step;	
	}
}
