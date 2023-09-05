/*
**	Problem 004: Largest palindrome product
**
**	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
**
**	Find the largest palindrome made from the product of two 3-digit numbers.
**
**	Solved in 4 ms.
*/

#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

bool	ft_is_palindrome(int nb)
{
	std::string	str;
	
	str = std::to_string(nb);	
	for (size_t i = 0; i < str.size() / 2 ; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
			return (false);
	}
	return (true);
}

int	main(void)
{
	int	result,
		biggest;

	auto start = std::chrono::system_clock::now();
	for (int i = 100 ; i < 1000 ; i++)
	{
		for (int j = 100 ; j < i + 1 ; j++)
		{
			result = i * j;
			if (result > biggest && ft_is_palindrome(result))
			{
//				std::cout << i << " " << j << std::endl;
				biggest = result;
			}
		}
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Largest palindrome is " << biggest << ", found in " << t.count() << " millisecond(s)." << std::endl;

	return (0);
}
