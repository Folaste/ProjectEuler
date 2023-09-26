"""
Problem 022: Names Scores

    Using 022_names.txt, a 46K file containing ive five-thousand first names,
    begin by sorting it into alphabetical order.
    Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list
    to obtain a name score.

    For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
    is the 938th name in the list. So, COLIN would obtain a score of 938 * 53 = 49714.

    What is the total of all the name scores in the file?

        Solved in 5 ms
"""

import time


def score(name):
    name_sum = 0
    for letter in name:
        name_sum += alpha_score[letter]
    return name_sum


start = time.time_ns()
alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
alpha_score = dict()
for i in range(len(alpha)):
    alpha_score[alpha[i]] = i + 1

with open("022_names.txt", 'r') as f:
    name_list = f.read()
    f.close()

name_list = name_list.replace('"', '').split(',')
name_list.sort()

total = 0
for i in range(len(name_list)):
    total += score(name_list[i]) * (i + 1)
end = time.time_ns()

print(__doc__)
print(f"Total of name scores if {total}, found in {round((end - start) / 1_000_000)} milliseconds.")
