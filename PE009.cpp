// Find the product of the only Pythagorean triplet (a2 + b2 = c2) that supports a + b + c = 1000

#include <iostream>

int	main(void)
{
	long result;

	for (int a = 1; a < 1000; a++)
	{
		for (int b = 1; b < 1000; b++)
		{
			for (int c = 1; c < 1000; c++)
			{
				if (a + b + c != 1000)
					continue;
				else if (a * a + b * b == c * c)
				{
					result = a * b * c;
					std::cout << a << " " << b << " " << c << std::endl;
					std::cout << "The product is " << result << std::endl;
					return (0);
				}
			}
		}
	}
	
	return (0);
}
