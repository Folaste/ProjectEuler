/*
**	Problem 016: Power digit sum
**	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
**
**	What is the sum of the digits of the number 2^1000?
*/

#include <string>
#include <iostream>
#include <cmath>

int main(void)
{
	std::string str;
	int result = 0;

	str = std::to_string(pow(2, 1000));
	str = str.substr(0, str.find('.')); // Removes dot and following because pow() returns a double

	for (size_t i = 0; i < str.size(); i++)
	{
		result += str[i] - '0';
	}

	std::cout << "Sum of all digits of 2^1000 is " << result << std::endl;

	return (0);
}
