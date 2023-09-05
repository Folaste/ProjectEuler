/*
**	Problem 005: Smallest multiple
**
**	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
**
**	What is the smallest positive number that is evenly divisible by all the numbers from 1 to 20?
*/

#include <iostream>

int	main(void)
{
	unsigned long long max = 1;

	for (int i = 2; i <= 20; i++)
		max *= i;

	for (unsigned long long i = 20 ; i < max; i++)
	{
		for (int j = 2; j <= 20; j++)
		{
			if (i % j != 0)
				break;
			if (j == 20)
			{
				std::cout << "This number is " << i << std::endl;
				return (0);
			}
		}
	}
	
	return (0);
}
