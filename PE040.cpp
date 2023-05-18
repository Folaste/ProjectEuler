/*
**	Problem 040: Champernowne's constant
**
** An irrational decimal fraction is created by concatenating the positive integers:
**
**		0.123456789101112131415161718192021...
**
**	It can be seen that the 12th digit of the fractional part is 1.
**
**	If dn represents the nth digit of the fractional part, find the value of the following expression.
**		d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <iostream>

int	main(void)
{
	int count = 1,
		product = 1;
	std::string frac_part;

	while (frac_part.size() <= 1000000)
	{
		frac_part += std::to_string(count);
		count++;
	}

	for (int i = 1; i <= 1000000; i *= 10)
		product *= frac_part[i - 1] - '0';

	std::cout << "Result of the expression is " << product << std::endl;
	return (0);
}