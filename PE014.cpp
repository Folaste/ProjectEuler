/*
**	Problem 014: Longest Collatz sequence
**
**	The following iterative sequence is defined for the set of positive integers:
**
**	n → n/2 (n is even)
**	n → 3n + 1 (n is odd)
**
**	Using the rule above and starting with 13, we generate the following sequence:
**
**		13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
**
**	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
**
**	Which starting number, under one million, produces the longest chain?
**
**	NOTE: Once the chain starts the terms are allowed to go above one million.
**
**	Solved in 333 ms. 
*/

#include <chrono>
#include <iostream>

int	main(void)
{
	unsigned int	max_count = 1,
					max_number = 1,
					n, count;

	auto start = std::chrono::system_clock::now();
	for (int i = 1; i <= 1000000; i++)
	{
		n = i;
		count = 0;
		while (n != 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;
			count++;
		}
		if (count > max_count)
		{
			max_count = count;
			max_number = i;
		}
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);  
	std::cout << "The number is " << max_number << ", found in " << t.count() << " microsecond(s)." << std::endl;
	return (0);
}
