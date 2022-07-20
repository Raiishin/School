import math


def binary_search(list, target):
    lo = 0
    hi = len(list) - 1
    mid = 0

    while (hi - lo > 1):
        mid = math.floor((lo + hi) / 2)
        if (list[mid] < target):
            lo = mid + 1
        else:
            hi = mid

    if (list[lo] == target):
        return lo
    elif (list[hi] == target):
        return hi
    else:
        return False


def main(list):
    list.sort()

    returnArr = []
    i = 0

    while (i < len(list)):
        number = list[i]
        squared = number * number

        index = binary_search(list, squared)

        if (index != False):
            if (index != i):
                returnArr.append([number, squared])

        i += 1

    return returnArr


answer = main([16, 9, 4, 7, 8, 3, 2, 3])
print(answer)
answer = main([15, 2, 3, 6, 5, 1, 6, 7])
print(answer)
