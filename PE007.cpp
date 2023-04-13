/*
**	Problem 007: 10001st prime	
**
**	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
**
**	What is the 10 001st prime number?
*/

#include <iostream>

int	ft_sqrt(int nb)
{
	int i = 0;
	if (2147395600 <= nb && nb <= 2147483647)
		return (46340);
	while (i * i <= nb)
		i++;
	return (--i);
}

bool	ft_is_prime(int nb)
{
	int	sqrt;

	if (nb <= 1)
		return (false);
	sqrt = ft_sqrt(nb);
	for (int i = 2 ; i <= sqrt; i++)
		if (nb % i == 0)
			return (false);
	return (true);
}

int	main(void)
{
	int	count = 0,
		nb = 1;

	while (count != 10001)
	{
		nb++;
		if (ft_is_prime(nb) == true)
			count++;
	}

	std::cout << "The 10001st prime number is " << nb << std::endl;
	
	return (0);
}
