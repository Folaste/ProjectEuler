"""
Problem 037: Truncatable primes

    The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits
    from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly, we can work from right to
    left: 3797, 379, 37, and 3.

    Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

    NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

    Solved in 1427 ms (1st version), in 172 ms (2nd version).
"""

import time


def eratosthenes_sieve(limit: int) -> list[bool]:
    table = [True] * limit
    table[0:2] = [False, False]
    for ind, val in enumerate(table):
        if val:
            table[ind * 2::ind] = [False] * (((limit - 1) // ind) - 1)
    return table


start = time.time_ns()
sieve = eratosthenes_sieve(1_000_000)


def is_prime(n: int) -> bool:
    return sieve[n]


prime_list = [i for i, val in enumerate(sieve) if val and i > 10]  # 2, 3, 5, 7 are not considered truncatable primes
result_list = []
for test_number in prime_list:
    str_test_number = str(test_number)
    truncatable = True
    for i in range(1, len(str_test_number)):
        if not is_prime(int(str_test_number[i:])) or not is_prime(int(str_test_number[:-i])):
            truncatable = False
            break
    if truncatable:
        result_list.append(test_number)
        if len(result_list) == 11:
            break


result = sum(result_list)
end = time.time_ns()

print(__doc__)
print(f"Sum of the only eleven primes that are both truncatable from left to right and right to left: {result},"
      f" found in {round((end-start) / 1_000_000)} ms")
