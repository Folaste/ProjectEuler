/*
**	Problem 015: Lattice paths	
**
**	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
**	there are exactly 6 routes to the bottom right corner.
**
**	How many such routes are there through a 20×20 grid?
**
**	Solved in 310 ns. 
*/

#include <chrono>
#include <iostream>

//	To find all the paths, we know that we have 20 moves to the right and 20 moves down to reach the end.
//	So, we have to choose 20 downward moves out of the 40 available moves, or 20 rightward moves out of the 40.
//	So the answer is the binomial coefficient (40, 20).

long long	binomial_coefficient(int n, int k)
{
	long long	result = 1;

	if (k < 0 || k > n)
		return (0);

	for (int i = 1; i <= k; i++)
	{
		result *= n - i + 1;
		result /= i;
	}

	return (result);
}


int	main(void)
{
	int k = 20,
		n = 40;

	long long ret;

	auto start = std::chrono::system_clock::now();
	ret = binomial_coefficient(n, k);
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "The number of paths is " << ret
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;

	return (0);
}
