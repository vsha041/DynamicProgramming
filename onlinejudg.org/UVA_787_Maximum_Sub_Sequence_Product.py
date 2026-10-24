#https://uva.onlinejudge.org/external/7/787.pdf

from sys import stdin


def solve(nums):
    allproducts = []
    for index, value in enumerate(nums):
        product = int(value)
        allproducts.append(product)
        for innerIndex, innerValue in enumerate(nums):
            if innerIndex <= index:
                continue
            product = product * int(innerValue)
            allproducts.append(product)
    return max(allproducts)



for line in stdin:
    numbers = line.split()[:-1]
    result = solve(numbers)
    print(result)