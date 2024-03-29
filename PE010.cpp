/*
**	Problem 010: Summation of primes 
**
**	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
**
**	Find the sum of all the primes below two million.
**
**	Solved in 3.340 s.
*/

#include <chrono>
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
	unsigned long	sum = 0;
	
	auto start = std::chrono::system_clock::now();
	for (int nb = 1; nb < 2000000 ; nb++)
		if (ft_is_prime(nb))
			sum += nb;
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "The sum is " << sum
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;
	
	return (0);
}
