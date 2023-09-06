/*
**	Problem 016: Power digit sum
**
**	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
**
**	What is the sum of the digits of the number 2^1000?
**
**	Solved in 40 us.
*/

#include <chrono>
#include <cmath>
#include <iostream>

int main(void)
{
	std::string str;
	int result = 0;

	auto start = std::chrono::system_clock::now();
	str = std::to_string(pow(2, 1000));
	str = str.substr(0, str.find('.')); // Removes dot and following because pow() returns a double

	for (size_t i = 0; i < str.size(); i++)
	{
		result += str[i] - '0';
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Sum of all digits of 2^1000 is " << result
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;

	return (0);
}
