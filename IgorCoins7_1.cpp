#include <iostream>
#include <cstdlib>
#include <time.h>

int integer_array[20];
int how_many;

int input() {
	//PURPOSE: Accept a single integer value, then more integers, the amount of which is equal to the first integer value
	//INPUTS: User inputted values
	//OUTPUTS: The single integer and the many others
	
	restart:
	std::cout << "Enter the amount of integers from 1 to 20 that you would like to enter: ";
	std::cin >> how_many; //the user enters the amount of integers from 1 to 20 they would like to enter
	std::cout << std::endl;
	if (how_many > 20 || how_many < 1) { //this checks if the user-inputted value is in the accepted range of 1 - 20
		std::cout << "I said 1 to 20... Try again.\n";
		goto restart; //the code jumps back to the start
	}
	return how_many; //returns the how_many variable for later use
	
}
void array_randomizer(int integer_amount) { 
	//PURPOSE: Take the amount of integers the will be entered into the array and add a randomized integer from 1-100 to them while adding them to an array
	//INPUTS: The amount of integers that the user wishes to input into the array
	//OUTPUT: The either filled or partially filled array
	for (int i = 0; i < integer_amount; i++) { //this for loop repeats until it has looped for the amount of times equal to the user inputted amount of integers
		int input_number; //declared input_number variable that will be used for the user inputted values to populate the array
		std::cout << "Enter an integer: ";
		std::cin >> input_number; //user inputs an integer
		std::srand((unsigned)time(0)); //randomizer is seeded
		input_number = input_number + (rand() % 100 + 1); //a random integer from 1 - 100 is added to the input_number
		integer_array[i] = input_number; //the array is populated with the new input_number
	}
}

void output() {
	//PURPOSE: Output all the numbers in the array in reverse order
	//INPUTS: The array
	//OUTPUTS: Prints the integers in the array
	std::cout << "The reverse order of the numbers you entered, with a little bit extra added to them is:\n";
	for (int i = how_many - 1; i >= 0; --i) { //this for loop iterates through the indices, printing them to console in a reverse order
		std::cout << integer_array[i] << std::endl;
	}
}

int main() {
	array_randomizer(input());
	output();
}