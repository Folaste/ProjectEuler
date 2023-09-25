"""
Problem 048: Self Powers

    The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

    Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

        Solved in 5 milliseconds
"""

import math
import time

start = time.time_ns()

total = 0
square = 0
for i in range (1, 1001):
    square = i ** i
    total += square

total = str(total)

last = total[-10:]
end = time.time_ns()

print(__doc__)
print(f"Ten last digits of the series are {last}, found in {round((end - start) / 1_000_000)} milliseconds.")
