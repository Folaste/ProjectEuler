/*
**	Problem 004: Largest palindrome product
**
**	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
**
**	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <sstream>

int	ft_intlen(int nb)
{
	int i = 1;

	while (nb >= 10)
	{
		i++;
		nb /= 10;
	}

	return (i);
}

const char*	ft_itoa(int nb)
{
	std::stringstream	ss;
	ss << nb;
	return (ss.str().c_str());
}

bool	ft_is_palindrome(int nb)
{
	const char*	str;
	int			len;
	
	len = ft_intlen(nb);
	str = ft_itoa(nb);	
	for (int i = 0; i < len / 2 ; i++)
	{
		if (str[i] != str[len - 1 - i])
			return (false);
	}
	return (true);
}

int	main(void)
{
	int	result,
		biggest;

	for (int i = 100 ; i < 1000 ; i++)
	{
		for (int j = 100 ; j < i + 1 ; j++)
		{
			result = i * j;
			if (ft_is_palindrome(result) == true && result > biggest)
			{
				std::cout << i << " " << j << std::endl;
				biggest = result;
			}
		}
	}

	std::cout << "The biggest palindrome is " << biggest << std::endl;

	return (0);
}
