// Find the biggest prime factor of 600851475143

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
