#include <stdio.h>


//NEED TO DECLARE METHODS BEFORE WE CAN USE THEM
void speak();
unsigned set_bits();


int main(){
	void speak();
	unsigned number = 3;
	unsigned answer = set_bits(number);
	printf(answer);

	return 0;	//necessary since main() is an int
}

/*
 * Simply prints Hello World
 */
void speak(){
	printf("Hello World\n");
}
/*
 * Returns an unsigned with n least signifigant bits set (the rest are zero)
 */
unsigned set_bits(unsigned n){
	//i.e. n=3, turn on last 3 bits
	return n<<3; //FIXME complete this method PLS
}
