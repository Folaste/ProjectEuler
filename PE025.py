"""
Problem 025: 1000-digit Fibonacci Number

    The Fibonacci sequence is defined by the recurrence relation:
        F(n) = F(n - 1) + F(n - 2), where F(1) = 1 and F(2) = 1

    Hence, the first 12 terms will be:
        F(1) = 1
        F(2) = 1
        F(3) = 2
        ...
        F(12) = 144

    The 12th term, F(12), is the first term to contain three digits.

    What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

        Solved in 18 ms
"""

import time

fibo_1 = 1
fibo_2 = 1
fibo_n = 0
i = 2

start = time.time_ns()
while True:
    fibo_n = fibo_1 + fibo_2
    i += 1
    if str(fibo_n).__len__() >= 1000:
        break
    else:
        fibo_1 = fibo_2
        fibo_2 = fibo_n
end = time.time_ns()

print(__doc__)
print(f"First term of Fibonacci sequence containing 1000 digits is index {i}, "
      f"found in {round((end - start) / 1_000_000)} milliseconds.")
