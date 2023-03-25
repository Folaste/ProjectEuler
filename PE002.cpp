//	Find the sum of even Fibonacci sequence bound to 4000000

#include <iostream>

int main(void)
{
	unsigned int sum = 0, fibo_1 = 1, fibo_2 = 2, tmp;

	sum += fibo_2;
	while (fibo_2 < 4000000)
	{
		tmp = fibo_1 + fibo_2;
		if (tmp % 2 == 0)
			sum += tmp;
		fibo_1 = fibo_2;
		fibo_2 = tmp;
	}
	std::cout << "Sum is " << sum << std::endl;
	return (0);
}
