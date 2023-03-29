// Find the difference between the sum of the squares of the first one hundred natural numbers
// and the square of the sum.

#include <iostream>

int	main(void)
{
	int	sum = 0,
		square_sum = 0;

	for (int i = 1; i <= 100; i++)
	{
		sum += i;
		square_sum += i * i;
	}

	sum *= sum;

	std::cout << "The difference is " <<  sum - square_sum << std::endl;

	return (0);
}
