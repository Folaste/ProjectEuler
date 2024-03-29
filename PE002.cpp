/*
**	Problem 002: Even Fibonacci numbers
**
**	Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
**
**	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
**
**	By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
**
**	Solved in 1200 ns.
*/

#include <chrono>
#include <iostream>

int main(void)
{
	unsigned int sum = 0, fibo_1 = 1, fibo_2 = 2, tmp;

	auto start = std::chrono::system_clock::now();
	sum += fibo_2;
	while (fibo_2 < 4000000)
	{
		tmp = fibo_1 + fibo_2;
		if (tmp % 2 == 0)
			sum += tmp;
		fibo_1 = fibo_2;
		fibo_2 = tmp;
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Sum is " << sum
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;
	return (0);
}
