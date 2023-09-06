/*
**	Problem 036: Double-base Palindromes
**
**	The decimal number, 585 = 1001001001[2] (binary), is palindromic in both bases.
**
**	Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
**
**	(Please note that the palindromic number, in either base, may not include leading zeros.)
**
**	Solved in 26 ms.
*/

#include <chrono>
#include <iostream>
#include <string>

using namespace std;

bool	isPalindromic(string s)
{
	int mid = s.size() / 2;

	for (int i = 0; i < mid; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
			return (false);
	}
	
	return (true);
}

string	tenToBin(int nb)
{
	string ret = "";

	while (nb > 0)
	{
		int bit = nb % 2;
		ret = to_string(bit) + ret;
		nb /= 2;
	}

	return (ret);
}

int main(void) 
{
	unsigned long sum = 0;
	string s;

	auto start = chrono::system_clock::now();
	for (int i = 1; i < 1000000; i++)
	{
		// Even numbers are skipped because they will never be even in base 2 (they end in 0).
		if (i % 2 == 0)
			continue;
		if (isPalindromic(to_string(i)) == true)
		{
			s = tenToBin(i);
			if (isPalindromic(s) == true)
				sum += i;
		}
	}
	auto end = chrono::system_clock::now();

	auto t = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "The sum is " << sum 
		<< ", found in " << t.count() << " microsecond(s)." << endl;
	
	return (0);
}
