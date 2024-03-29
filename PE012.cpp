/*
**	Problem 012: Highly divisible triangular number
**
**	The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
**
**	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
**
**	Let us list the factors of the first seven triangle numbers:
**	
**		 1: 1
**		 3: 1,3
**		 6: 1,2,3,6
**		10: 1,2,5,10
**		15: 1,3,5,15
**		21: 1,3,7,21
**		28: 1,2,4,7,14,28
**
**	We can see that 28 is the first triangle number to have over five divisors.
**
**	What is the value of the first triangle number to have over five hundred divisors?
**
**	Solved in 30:24 min.
*/

#include <chrono>
#include <cmath>
#include <iostream>

int main(void)
{
	unsigned long long	triangular = 0;
	unsigned long long	add = 0;
	int					count_div = 0;
	
	auto start = std::chrono::system_clock::now();
	while (count_div < 500)
	{
		count_div = 0;
		triangular += ++add;

		for (unsigned long long i = 1; i <= triangular; i++)
			if (triangular % i == 0)
				count_div++;
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "This number is " << triangular
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;

	return (0);
}
