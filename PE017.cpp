/*
**	Problem 017: Number letter counts
**
**	If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
**
**	If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
**
**	NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
**	The use of "and" when writing out numbers is in compliance with British usage.
**
**	Solved in 3600 us. 
*/

#include <chrono>
#include <iostream>
#include <map>

std::map<int, std::string>	createDictionary(void)
{
	std::map<int, std::string>	dict = {
		{0, ""},
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"},
		{5, "five"},
		{6, "six"},
		{7, "seven"},
		{8, "eight"},
		{9, "nine"},
		{10, "ten"},
		{11, "eleven"},
		{12, "twelve"},
		{13, "thirteen"},
		{14, "fourteen"},
		{15, "fifteen"},
		{16, "sixteen"},
		{17, "seventeen"},
		{18, "eighteen"},
		{19, "nineteen"},
		{20, "twenty"},
		{30, "thirty"},
		{40, "forty"},
		{50, "fifty"},
		{60, "sixty"},
		{70, "seventy"},
		{80, "eighty"},
		{90, "ninety"},
		{100, "hundred"},
		{1000, "thousand"}
	};

	return (dict);
}

std::string	decomposeNumber(std::map<int, std::string> dict, int nb)
{
	std::string	ret;

	if (nb == 1000)
	{
		ret += dict[1];
		ret += dict[1000];
		nb = 0;
	}

	if (nb >= 100)
	{
		ret += dict[nb / 100];
		ret += dict[100];
		nb -= (nb / 100) * 100;
		if (nb != 0)
			ret += "and";
	}

	if (nb > 20)
	{
		ret += dict[(nb / 10) * 10];
		ret += dict[nb % 10];
	}
	else if (nb > 0)
	{
		ret += dict[nb];
	}

	return (ret);
}


int	main(void)
{
	std::map<int, std::string>	dict;
	long						result = 0;
	std::string					number;

	auto start = std::chrono::system_clock::now();
	dict = createDictionary();
	for (int i = 1; i <= 1000; i++)
	{
		number = decomposeNumber(dict, i);
//		std::cout << number << std::endl;
		result += number.size();
		number.erase();
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Number of letters to write all numbers from 1 to 1000 is " << result 
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;

	return (0);
}
