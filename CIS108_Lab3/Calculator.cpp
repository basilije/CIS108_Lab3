using namespace std;

float result=0;
float tenth = 0;
bool decimal = false;

float doSomething(int input_int)
{
	switch (input_int)
	{
	case 46: // "."
		decimal = not(decimal);
	case 48: // "0"
		if (not(decimal))
			result *= 10;
		else
			result = result;
		break;
	case 49: // "1"
		if (not(decimal))
		{
			result *= 10;
			result += 1;
		}
		else
		{
			result = ((result * 10) + 1) / 10;
		}
		break;
	case 50: // "2"
		if (not(decimal))
		{
			result *= 10;
			result += 2;
		}
		break;
	case 51: // "3"
		if (not(decimal))
		{
			result *= 10;
			result += 3;
		}
		break;
	case 52: // "4"
		if (not(decimal))
		{
			result *= 10;
			result += 4;
		}
		break;
	case 53: // "5"
		if (not(decimal))
		{
			result *= 10;
			result += 5;
		}
		break;
	case 54: // "6"
		if (not(decimal))
		{
			result *= 10;
			result += 6;
		}
		break;
	case 55: // "7"
		if (not(decimal))
		{
			result *= 10;
			result += 7;
		}
		break;
	case 56: // "8"
		if (not(decimal))
		{
			result *= 10;
			result += 8;
		}
		break;
	case 57: // "9"
		if (not(decimal))
		{
			result *= 10;
			result += 9;
		}
		break;
	default:
		result = result;
		break;
	}
	
	return result;
}
