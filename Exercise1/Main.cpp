#include <iostream>
#include <iomanip>
#include <string>
#include "conio.h"
#include "Calculator.h"

using namespace std;

// the function used to return the formated string from te number
string intOrdoubleToString(double int_or_double_number)
{
	string to_return;

	// if it zero, return the empty string
	if (int_or_double_number == 0)
		to_return = "";
	else
	{
		// if the number have no decimals, return just the int part
		if (int_or_double_number == static_cast<int>(int_or_double_number))
			to_return = to_string(static_cast<int>(int_or_double_number));

		// but if there are decimals
		else
		{
			// take number with decimals
			to_return = to_string(int_or_double_number);

			// but cut the zeros if remaining
			int i = to_return.length();
			while (to_return[i - 1] == '0')
			{
				to_return.erase(i - 1, 1);
				i = to_return.length();
			}

		}
	}
	return to_return;
}

int main()
{
	int get_key; // integer to store ascii code of the key pressed
	string key_sequence; // string to store the current key sequence
	double calculator_response = 0; // double to store the response from the calculator
	bool ops_in_progress = false; // bool to store is some +-*/^ operation in progress
	string previous_key_sequence = ""; // string to remember the previous key sequnce
	string key_sequence_to_print = ""; // string to use what will print on the screen
	char char_key; // char to store char pressed

	cout << "\r> "; // write "the prompt" on the screen

	do {
		get_key = _getch(); //  take the ascii of the pressed key
		char_key = char(get_key); // take the char pressed

		// just if not "I", "C", "R", or "S" key is pressed, add the key to the key sequence
		if (char_key != 'i' && char_key != 'I' && char_key != 'c' && char_key != 'C' && char_key != 'r' && char_key != 'R' && char_key != 's' && char_key != 'S')
			key_sequence += char_key;

		// if +-*/ is pressed
		if (char_key == '+' || char_key == '-' || char_key == '*' || char_key == '/' || char_key == '^')
		{
			previous_key_sequence = key_sequence; // copy the previous key sequence in other variable
			ops_in_progress = true; // set variable to know that calculation operation is in progress
		}

		// get the response from the calculator
		calculator_response = doSomething(get_key);

		// if "Enter", "C" or "R" is pressed, print the response from calculator
		if (get_key == 13 || char_key == 'c' || char_key == 'C' || char_key == 'r' || char_key == 'R')
		{
			ops_in_progress = false; // some +-*/ operation is definitely not in progress 
			key_sequence = intOrdoubleToString(calculator_response); // get the response from the calculator
			cout << "\r                              "; // clear the screen remainings
			cout << "\r> " << key_sequence_to_print << "\n" << key_sequence << "\n"; // print the 
			previous_key_sequence = ""; // delete the previous key sequence
			key_sequence = ""; // delete the key sequence
		}

		// if there is no response "0" and ops_in_progress is true, that means we entering second number,
		// so print the first number and current
		if (calculator_response != 0 && ops_in_progress)
			key_sequence_to_print = previous_key_sequence + intOrdoubleToString(calculator_response);
		
		// in other case, just add the key to the sequence needed to print
		else
			key_sequence_to_print = key_sequence;


		// print the empty row that will clear remaining digits if exists
		cout << "\r                              ";
		// print the key sequence we remembered
		cout << "\r> " << key_sequence_to_print;

		// repeat until "x" or "X" is pressed
	} while (char_key != 'x' && char_key != 'x');

	return 0;
}
