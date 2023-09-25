"""
Problem 020: Factorial Digit Sum

  n! means n * (n - 1) * ... * 3 * 2 * 1.

  For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
  and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

  Find the sum of the digits in the number 100!.

      Solved in
"""

import time

start = time.time_ns()
n = 100
x = 1
sum = 0

for i in range(1, n + 1):
    x = x * i

for digit in str(x):
    sum += int(digit)
end = time.time_ns()

print(f"Sum of all digits of 100! is {sum}, found in {round((end - start) / 1000)} microseconds")