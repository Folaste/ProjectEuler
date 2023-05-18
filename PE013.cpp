/*
**	Problem 013: Large sum
**
**	Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
**	(In file 13_numbers.txt)
*/

#include <fstream>
#include <iostream>

int	main(void)
{
	std::ifstream					file;
	std::string						buf;
	unsigned long long				tmp,
									ret = 0;

	file.open("13_numbers.txt");
	if (!file.is_open())
		exit(1);

	while (getline(file, buf))
	{
		buf = buf.substr(0, 11); // Taking only the 11th first digits to have a good precision.
		tmp = atoll(buf.c_str());
		ret += tmp;
	}
	file.close();

	buf = std::to_string(ret);
	buf = buf.substr(0, 10);

	std::cout << "First digits of this sum is " << buf << std::endl;

	return (0);
}
