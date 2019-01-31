#include <math.h> 

double first_number = 0;
double second_number = 0;
double result_to_return = 0;
double memory_value = 0;
int decimal_place = 0;
int number_in_use = 1;
char operation_in_progress = char(0);
int digit;
char char_key;

void resetWorkingParameters()
{
	second_number = 0;
	decimal_place = 0;
	operation_in_progress = 0;
	//first_number = result_to_return;
}

double doSomething(int pressed_key)
{
	char_key = char(pressed_key);
	switch (char_key)
	{

		// "0", "1", "2", "3', "4", "5", "6", "7", "8", "9"
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

		// "."
	case '.':
		if (decimal_place == 0)
			decimal_place = 1;
		break;

		// "*"
	case '*':
		operation_in_progress = char_key;
		number_in_use = 2;
		second_number = 0;
		decimal_place = 0;
		break;

		// "+"
	case '+':
		operation_in_progress = char_key;
		number_in_use = 2;
		second_number = 0;
		decimal_place = 0;
		break;

		// "-"
	case '-':
		operation_in_progress = char_key;
		number_in_use = 2;
		second_number = 0;
		decimal_place = 0;
		break;

		// "/"
	case '/':
		operation_in_progress = char_key;
		number_in_use = 2;
		second_number = 0;
		decimal_place = 0;
		break;

		// "^"
	case '^':
		operation_in_progress = char_key;
		number_in_use = 2;
		second_number = 0;
		decimal_place = 0;
		break;

		// "ENTER"
	case char(13):
		switch (operation_in_progress)
		{

		case '*': // "*"
			result_to_return = first_number * second_number;
			first_number = result_to_return;
			//resetWorkingParameters();
			second_number = 0;
			decimal_place = 0;
			operation_in_progress = 0;
			break;

		case '+': // "+"
			result_to_return = first_number + second_number;
			first_number = result_to_return;
			//resetWorkingParameters();
			second_number = 0;
			decimal_place = 0;
			operation_in_progress = 0;
			break;

		case '-': // "-"
			result_to_return = first_number - second_number;
			first_number = result_to_return;
			//resetWorkingParameters();
			second_number = 0;
			decimal_place = 0;
			operation_in_progress = 0;
			break;

		case '/': // "/"
			result_to_return = first_number / second_number;
			first_number = result_to_return;
			//resetWorkingParameters();
			second_number = 0;
			decimal_place = 0;
			operation_in_progress = 0;
			break;

		case '^': // "^"
			result_to_return = pow(first_number, second_number);
			first_number = result_to_return;
			//resetWorkingParameters();
			second_number = 0;
			decimal_place = 0;
			operation_in_progress = 0;
			break;

		}
		break;

		// "c", "C"
	case 'c': case 'C':
		result_to_return = 0;
		first_number = result_to_return;
		number_in_use = 1;
		break;

		// "s", "S"
	case 's': case 'S':
		memory_value = result_to_return;
		break;

		// "r", "R"
	case 'r': case 'R':
		result_to_return = memory_value;
		first_number = result_to_return;
		number_in_use = 1;
		break;

		// "m", "M"
	case 'm': case 'M':
		memory_value = 0;

		break;

		// "i", "I"
	case 'i': case 'I':
		first_number = 0 - result_to_return;
		number_in_use = 1;
		break;


	default:
		result_to_return = result_to_return;
		break;
	}

	// not "ENTER"
	if (pressed_key != char(13))
	{
		if (number_in_use == 1)
			result_to_return = first_number;
		else
			result_to_return = second_number;
	}

	return result_to_return;
}
