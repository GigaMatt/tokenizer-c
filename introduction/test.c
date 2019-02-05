#include <stdio.h>	//library that provides several functions for reading/writing one character at a time (getChar() putChar())
#include <stdlib.h>

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
	void precision_notes();
	void looping();
	void char_input_output();
	void reading_copying_strings_files();
	void getChar_character_counting();

	int number = 6;
	void c_recursion(number);

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

/**
 * NOTES ON PRECISION AS SEEN IN PREVIOUS FUNCTION
 */ 
void precision_notes(){
	/**
	 * %d		Print as a decimal integer value
	 * %6d		Print as a decimal integer value AT LEAST 6 CHARACTERS WIDE
	 * 
	 * %f		Print as a floating-point number
	 * %6f		Print as a floating-point number AT LEAST 6 CHARACTERS WIDE
	 * 
	 * %.2f		Print as a floating-point number 2 CHARACTERS AFTER THE DECIMAL 
	 * %6 .2f	Print as a floating-point number 2 CHARACTERS AFTER THE DECIMAL && AT LEAST 6 CHARACTERS WIDE
	 */
}

/**
 * NOTES ON LOOPING IN C
 */ 
void looping(){
	//For-Statement (relativly similar to Java)
	int faren;
	for(faren =0; faren<=300; faren+= 20){	//TODO verifty += works in looping in both Java and C
		printf("%3d %6.1f\n", faren, (5.0/9.0)*(faren-32));
	}

	//While-Statement (also similar to Java)
	//Also refer to arithmetic_variables() method for similar example
	faren=0;
	while(faren<=300){
		printf("%3d %6.1f\n", faren, (5.0/9.0)*(faren-32));
		faren+=20;
	}
}

/**
 * BASIC CHAR INPUT/OUTPUT IN C
 */ 
void char_input_output(){
	//Recall stdio.h library provides several functions for reading/writing one character at a time
	//NOTE THIS IS SPECIFICALLY FOR CHARS (NOT STRINGS!)
	int c;
	
	printf("Enter Value: \n");
	c = getchar();

	printf("\nYou Entered: ");
	putchar(c);

	printf("\n");
}

/**
 * FILE COPYING
 */
void reading_copying_strings_files(){
	int c;
	c=getchar();

	//THIS IS USEFULE FOR READING STRINGS/FILES
	while(c!=EOF){		//end of file
		putchar(c);		//output character read
		c.getChar();	//read another character
	}

	//ALTERNATIVELY
	int ch;
	while((c=getchar() != EOF){		//EOF IS AN INCLUDED LIBRARY
		putchar(c);
	}
}

/**
 * CHARACTER COUNTING WITH getChar()
 */
void getChar_character_counting(){
	long n_char = 0;
	while(getchar()!=EOF)
		n_char++;
	printf("%d\n", n_char);
}

/**
 * RECURSION: PRINTS NUMBER IN DECIMAL FORM
 */
void c_recursion(int number){
	if(number<0){
		putchar('-');
		n-=n;
	}

	if(number/10)
		c_recursion(number/10);
	putchar(number%10+'0');
}