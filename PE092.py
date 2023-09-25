"""
Problem 092: Square Digit Chain

    A number chain is created by continuously adding the square of the digits in a number to form a new number until it
    has been seen before.

    For example,
        44 -> 32 -> 13 -> 10 -> 1 -> 1
        85 -> 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89

    Therefore, any chain that arrives at 1 or 89 will become stuck in an endless loop.
    What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

    How many starting numbers below ten million will arrive at 89?

        Solved in 100 seconds.
"""

import time


def chain(nb):
    while nb != 1 and nb != 89:
        s = str(nb)
        nb = 0
        for sub_nb in s:
            nb += int(sub_nb) ** 2
    if nb == 1:
        return False
    return True


start = time.time()
count = 0
for i in range(1, 10_000_000):
    if chain(i):
        count += 1
end = time.time()

print(__doc__)
print(f"Starting numbers that arrive at 89 are {count}, found in {end - start} seconds.")
