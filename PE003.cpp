// Find the biggest prime factor of 600851475143

#include <iostream>

int main(void)
{
	unsigned long long	max	= 600851475143,
						prime;

	for (unsigned long long i = 2 ; i < 600851475143; i++)
	{
		for (unsigned long long j = 2 ; j < i ; j++)
			if (j % i == 0)
				continue;
		
		if (max % i == 0)
			prime = i;
		std::cout << prime << std::endl;
	}

	std::cout << "Biggest prime factor of 600851475143 is " << prime << std::endl;

	return (0);
}
