/*
**	Problem 003: Largest prime factor
**
**	The prime factors of 13195 are 5, 7, 13 and 29.
**
**	What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>

int main(void)
{
	unsigned long long	max	= 600851475143;

	for (unsigned long long i = 2 ; i < max; i++)
	{
		if (max % i == 0)
			max /= i;
	}

	std::cout << "Biggest prime factor of 600851475143 is " << max << std::endl;

	return (0);
}
