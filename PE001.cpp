/*
**	Problem 001: Multiples of 3 or 5
**
**	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
**
**	Find the sum of all the multiples of 3 or 5 below 1000.
**
**	Solved in 3 us.
*/

#include <chrono>
#include <iostream>

int	main(void)
{
	int sum = 0;

	auto start = std::chrono::system_clock::now();
	for (int i = 1; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Sum is " << sum 
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;

	return (0);
}
