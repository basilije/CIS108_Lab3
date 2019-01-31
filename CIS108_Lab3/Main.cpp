#include <iostream>
#include <iomanip>

#include <string>
#include "conio.h"

#include "Calculator.h"

using namespace std;

int main()
{
	int chr_int = 0;
	float hm;
	std::cout << std::setprecision(20);

	do {
		chr_int = _getch();
		hm = doSomething(chr_int);
		// cout << chr_int << " _ " << hm << endl;
		cout << hm << endl;
	} while (chr_int != 120);


	return 0;
}