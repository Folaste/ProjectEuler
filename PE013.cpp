/*
**	Problem 013: Large sum
**
**	Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
**	(In file 13_numbers.txt)
**
**	Solved in 2 ms.
*/

#include <chrono>
#include <fstream>
#include <iostream>

int	main(void)
{
	std::ifstream					file;
	std::string						buf;
	unsigned long long				tmp,
									ret = 0;

	auto start = std::chrono::system_clock::now();
	file.open("files/numbers.txt");
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
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "First digits of this sum is " << buf
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;

	return (0);
}
