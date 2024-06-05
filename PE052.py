"""
Problem 052: Permuted multiples

    It can be seen that the number 125874, and its double 251748,
    contain exactly the same digits, but in a different order.

    Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
    contain the same digits.

    Solved in 225 ms.

"""

import time

start = time.time_ns()
i = 1

while True:
    num_2x = str(i * 2)
    num_3x = str(i * 3)
    num_4x = str(i * 4)
    num_5x = str(i * 5)
    num_6x = str(i * 6)
    if sorted(num_2x) == sorted(num_3x) == sorted(num_4x) == sorted(num_5x) == sorted(num_6x):
        break
    else:
        i += 1
end = time.time_ns()

print(__doc__)
print(f"Smallest positive integer x such that 2x, 3x, 4x, 5x, and 6x contain the same digits is {i}, "
      f"found in {round((end - start) / 1_000_000)} milliseconds.")