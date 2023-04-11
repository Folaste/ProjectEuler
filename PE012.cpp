// Find the first triangular number that counts over 500 divisors

#include <cmath>
#include <iostream>

int main(void)
{
	unsigned long long	triangular = 0;
	unsigned long long	add = 0;
	int					count_div = 0;
	
	while (count_div < 500)
	{
		count_div = 0;
		triangular += ++add;

//		std::cout << triangular;

		for (unsigned long long i = 1; i <= triangular; i++)
		{
			if (triangular % i == 0)
			{
				count_div++;
//				if (triangular / i != i)
//					count_div++;
			}
		}
//		std::cout << " , " << count_div << std::endl;
	}

	std::cout << "This number is " << triangular << std::endl;

	return (0);
}
