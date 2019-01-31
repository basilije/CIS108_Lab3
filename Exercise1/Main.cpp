#include <iostream>
#include <iomanip>
#include <string>
#include "conio.h"
#include "Calculator.h"

using namespace std;

string intOrDoubleToString(double int_or_double_number)
{
	string to_return;
	if (int_or_double_number == 0)
		to_return = "";
	else
	{
		if (int_or_double_number == static_cast<int>(int_or_double_number))
			to_return = to_string(static_cast<int>(int_or_double_number));
		else
		{
			to_return = to_string(int_or_double_number);
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
	int get_key = 0;
	string key_sequence;
	double calculator_response = 0;
	bool ops_in_progress = false;
	string previous_key_sequence = "";
	string key_sequence_to_print = "";
	char char_key;
	cout << "\r> ";
	do {


		get_key = _getch();
		char_key = char(get_key);

		// not "i", "I", "c", "C", "r", "R", "s", "S"
		if (char_key != 'i' && char_key != 'I' && char_key != 'c' && char_key != 'C' && char_key != 'r' && char_key != 'R' && char_key != 's' && char_key != 'S')
			key_sequence += char_key;

		// +, -, *, /, ^
		if (char_key == '+' || char_key == '-' || char_key == '*' || char_key == '/' || char_key == '^')
		{
			previous_key_sequence = key_sequence;
			ops_in_progress = true;
		}

		calculator_response = doSomething(get_key);

		//"ENTER", "C", "c", "R", "r"
		if (get_key == 13 || char_key == 'c' || char_key == 'C' || char_key == 'r' || char_key == 'R')
		{
			ops_in_progress = false;
			key_sequence = intOrDoubleToString(calculator_response);
			cout << "\r                              ";
			cout << "\r> " << key_sequence_to_print << "\n" << key_sequence << "\n";
			previous_key_sequence = "";
			key_sequence = "";
		}

		if (calculator_response != 0 && ops_in_progress)
			key_sequence_to_print = previous_key_sequence + intOrDoubleToString(calculator_response);
		else
			key_sequence_to_print = key_sequence;

		cout << "\r                              ";
		cout << "\r> " << key_sequence_to_print;

		// "x" or "X"
	} while (char_key != 'x' && char_key != 'x');

	return 0;
}
