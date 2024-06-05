"""
Problem 037: Truncatable primes

    The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits
    from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly, we can work from right to
    left: 3797, 379, 37, and 3.

    Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

    NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

    Solved in 1427 ms.
"""

import time


def is_prime(number: int) -> bool:
    if number < 2:
        return False
    if number == 2:
        return True
    if number % 2 == 0:
        return False
    for mod in range(3, int(number ** 0.5) + 1, 2):
        if number % mod == 0:
            return False
    return True


start = time.time_ns()
test_number = 11
prime_list = []

while len(prime_list) != 11:
    if is_prime(test_number):
        truncatable = True
        for i in range(1, len(str(test_number))):
            if not is_prime(int(str(test_number)[i:])) or not is_prime(int(str(test_number)[:-i])):
                truncatable = False
                break
        if truncatable:
            prime_list.append(test_number)
    test_number += 2

result = sum(prime_list)
end = time.time_ns()

print(__doc__)
print(f"Sum of the only eleven primes that are both truncatable from left to right and right to left: {result},"
      f" found in {round((end-start) / 1_000_000)} ms")