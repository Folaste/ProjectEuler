/*
**	Problem 019: Counting Sundays
**
**	You are given the following information, but you may prefer to do some research for yourself.
**
**	  - 1 Jan 1900 was a Monday.
**	  - Thirty days has September,
**		April, June and November.
**		All the rest have thirty-one,
**		Saving February alone,
**		Which has twenty-eight, rain or shine.
**		And on leap years, twenty-nine.
**	  - A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
**
**	How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
**
**	Solved in 450 us.
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>

std::map<int, std::string>	g_dict = {
	{0, "mon"},
	{1, "tue"},
	{2, "wed"},
	{3, "thr"},
	{4, "fri"},
	{5, "sat"},
	{6, "sun"}
};

int	main(void)
{
	int count = 0,
		current_day = 0, // Day of 1st Jan 1900
		feb_days;

	std::vector<int>	day_31_months = {1, 3, 5, 7, 8, 10, 12},
						day_30_months = {4, 6, 9, 11};

	auto start = std::chrono::system_clock::now();
	current_day += 365 % 7; // Day of 1st Jan 1901;
	for (int year = 1901 ; year <= 2000; year++)
	{
		if (year % 4 == 0) // Only way to have a leap year
			feb_days = 29;
		else
			feb_days = 28;
		for (int month = 1; month <= 12; month++)
		{
			if (std::find(day_30_months.begin(), day_30_months.end(), month) != day_30_months.end())
				current_day += 30 % 7;
			else if (std::find(day_31_months.begin(), day_31_months.end(), month) != day_31_months.end())
				current_day += 31 % 7;
			else
				current_day += feb_days % 7;
			current_day %= 7;
			if (g_dict[current_day] == "sun")
				count++;
		}
	}
	auto end = std::chrono::system_clock::now();

	auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Number of Sundays falling on the day of the month in the 20th century is " << count 
		<< ", found in " << t.count() << " microsecond(s)." << std::endl;
	return (0);
}
