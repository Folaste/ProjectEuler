/*
**	Problem 003: Largest prime factor
**
**	The prime factors of 13195 are 5, 7, 13 and 29.
**
**	What is the largest prime factor of the number 600851475143 ?
**
**	Solved in 232 us.
*/

#include <chrono>
#include <iostream>

int main(void)
{
	unsigned long long	max	= 600851475143;

	auto start = std::chrono::system_clock::now();
	for (unsigned long long i = 2 ; i < max; i++)
	{
		if (max % i == 0)
			max /= i;
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "The largest prime factor is " << max << ", found in " << t.count() << " microsecond(s)."<< std::endl;

	return (0);
}
