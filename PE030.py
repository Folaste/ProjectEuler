"""
Problem 030: Digit fifth powers

    Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
        1634 = 1^4 + 6^4 + 3^4 + 4^4
        8208 = 8^4 + 2^4 + 0^4 + 8^4
        9474 = 9^4 + 4^4 + 7^4 + 4^4
    As 1 = 1^4 is not a sum it is not included

    The sum of these numbers is 1634 + 8208 + 9474 = 19316.

    Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

    Solved in 620 ms.
"""

import time

start = time.time_ns()
result = 0
for i in range(10, 354294):  # Value of 354294 was calculated by 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 for 999999 situation
    fifth_powers_sum = 0
    for digit in str(i):
        fifth_powers_sum += int(digit) ** 5

    if fifth_powers_sum == i:
        result += i

end = time.time_ns()

print(__doc__)
print(f"The sum of all numbers that can be written as the sum of fifth powers of their digits is {result},"
      f"found in {round((end - start) / 1_000_000)} milliseconds.")


