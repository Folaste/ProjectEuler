/*
**	Problem 006: Sum square difference
**
**	The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385
**
**	The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)^2 = 55^2 = 3025
**
**	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
**
**	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
**
**	Solved in 1530 ns.
*/

#include <chrono>
#include <iostream>

int	main(void)
{
	int	sum = 0,
		square_sum = 0;

	auto start = std::chrono::system_clock::now(); 
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
		square_sum += i * i;
	}

	sum *= sum;
	auto end = std::chrono::system_clock::now(); 

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Difference is " <<  sum - square_sum
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;

	return (0);
}
