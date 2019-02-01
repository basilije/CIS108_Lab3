#include <math.h> 

double first_number = 0; // double to store the first number we use
double second_number = 0; // double to store the second number we use
double result_to_return = 0; // double to store result we neeed to return
double memory_value = 0;  // double to store the memory when needed
int decimal_place = 0; // int used to remember on which decimal places we are during entering the number
int number_in_use = 1; // int used to remember with which number we currently operate
char operation_in_progress = char(0); // char that remember which calculation operation we currenty use
int digit; // int used to store which digit is currently pressed
char char_key; // char to store the current pressed key

// main function in this file that response with calculation needed
double doSomething(int pressed_key)
{
	char_key = char(pressed_key); // convert the int to the char actually pressed
	switch (char_key)
	{

	// if the digit is pressed
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		digit = pressed_key - 48;
		if (decimal_place == 0)
		{
			if (number_in_use == 1)
			{
				first_number *= 10;
				first_number += digit;
			}
			if (number_in_use == 2)
			{
				second_number *= 10;
				second_number += digit;
			}
		}
		else
		{
			double decimal = digit / (pow(10, decimal_place));
			if (number_in_use == 1)
				first_number = first_number + decimal;
			if (number_in_use == 2)
				second_number = second_number + decimal;
			//result = Round(result, decimal_place);
			decimal_place += 1;
		}
		break;

	// if the dot is pressed
	case '.':
		if (decimal_place == 0)
			decimal_place = 1;
		break;

	// if some calculation button is pressed
	case '*': case '+': case '-': case '/': case '^':
		operation_in_progress = char_key;
		number_in_use = 2;
		second_number = 0;
		decimal_place = 0;
		break;


	// if "Enter" is pressed
	case char(13):
		// determine which calculation button is previously pressed
		switch (operation_in_progress)
		{
		case '*': // "*"
			result_to_return = first_number * second_number;
			break;

		case '+': // "+"
			result_to_return = first_number + second_number;
			break;

		case '-': // "-"
			result_to_return = first_number - second_number;
			break;

		case '/': // "/"
			result_to_return = first_number / second_number;
			break;

		case '^': // "^"
			result_to_return = pow(first_number, second_number);
			break;
		}

		// reset variables after calculation
		first_number = result_to_return;
		second_number = 0;
		decimal_place = 0;
		operation_in_progress = 0;
		break;

		// if the clear key is pressed
	case 'c': case 'C':
		result_to_return = 0;
		first_number = result_to_return;
		number_in_use = 1;
		break;

		// if the store memory key is pressed
	case 's': case 'S':
		memory_value = result_to_return;
		break;

		// if the restore memory key is pressed
	case 'r': case 'R':
		result_to_return = memory_value;
		first_number = result_to_return;
		number_in_use = 1;
		break;

		// if the memory clear key is pressed
	case 'm': case 'M':
		memory_value = 0;
		break;

		// if the key for inversion is pressed
	case 'i': case 'I':
		first_number = 0 - result_to_return;
		number_in_use = 1;
		break;


	default:
		result_to_return = result_to_return;
		break;
	}

	// if not "Enter" is pressed determine which number to return
	if (pressed_key != char(13))
	{
		if (number_in_use == 1)
			result_to_return = first_number;
		else
			result_to_return = second_number;
	}

	return result_to_return;
}
