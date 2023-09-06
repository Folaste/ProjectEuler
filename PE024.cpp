/*
**	Problem 024 : Lexicographical permutations
**
**	A permutation is an ordered arrangement of objects. 
**	For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. 
**	The lexicographic permutations of 0, 1 and 2 are:
**
**	012, 021, 102, 120, 201, 210
**
**	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
**
**	Solved in 04:47 min.
*/

#include <iostream>
#include <chrono>
#include <cstring>
#include <string>
#include <limits>

using namespace std;

bool	isPermutation(unsigned long nb)
{
	int test[10]; //Each cell of the table represents the number of times the number is found.
	bzero(&test, sizeof(test));

	string s = to_string(nb);

	for (size_t i = 0; i < s.size(); i++)
		test[s[i] - '0']++;

	if (test[0] > 1)
		return (false);
	
	for (int i = 1; i < 10; i++)
		if (test[i] != 1)
			return (false);
	
	return (true);
}

int	main(void)
{
	unsigned long	test = 123456789;
	int				nb_perm = 0;

	auto start = chrono::system_clock::now();
	while (nb_perm != 1000000)
	{
		if (isPermutation(test) == true)
			nb_perm++;
		test++;
	}
	auto end = chrono::system_clock::now();

	auto t = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "The millionth permutation of all digits is " << --test 
		<< ", found in " << t.count() << " microsecond(s)." << endl;

	return (0);
}
