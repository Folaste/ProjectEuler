"""
Problem 024 : Lexicographical permutations

    A permutation is an ordered arrangement of objects.
    For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
    If all the permutations are listed numerically or alphabetically, we call it lexicographic order.
    The lexicographic permutations of 0, 1 and 2 are:

        012, 021, 102, 120, 201, 210

    What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

        Solved in 556 ms.
"""

import time
from itertools import permutations

start = time.time_ns()

digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
s = ""

permutation_list = list(permutations(digits))
millionth = permutation_list[999999]
for digit in millionth:
    s += str(digit)
millionth = int(s)

end = time.time_ns()

print(__doc__)
print(f"Millionth lexicographic permutation of all digits is {millionth}, "
      f"found in {round((end - start)/ 1000000)} milliseconds.")
