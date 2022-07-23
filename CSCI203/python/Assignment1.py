"""
Pseudocode

define a find_pivot function taking in three arguments, a list, a lower and higher index value
    Declare a variable to store the rightmost element as the pivot
    Declare a variable to serve as a pointer for a greater element

    Iterate and compare each element in the list 
        if the current element is smaller or equal to the pivot, swap its place with the greater element 

    return the pointer + 1

define a quick_sort function taking in three arguments, a list, the lower and upper bounds of the list
    check if the lower bound is smaller than the upper bound
        Find the pivot element in the list such that the elements smaller than the pivot are on the left and elements greater than the pivot are on the right
        Perform a recursive call on quick_sort on the left and right of the pivot

define a binary_search function taking in two arguments, a list and the target number you are looking for   
    declare the high, low and middle index values.
    while high - low is more than 1
        middle = (low + high)/2
        if the middle index in the list is smaller than the target number
            low = middle index + 1
        else
            high = middle index

    if the low index in the list is equal to the target number, return the low index
    else if the high index in the list is equal to the target number, return the high index
    else return -1

define a main function with an input argument of L
    Perform a quick_sort on L 

    Declare an Array, returnArr, which will be used to store valid number pairs
    Declare a counter to iterate through sorted L

    While counter is less than length of L, iterating through each element in L
        Declare a variable to store the current element
        Declare a variable to store the squared value of the current element

        Perform a binary_search to find if there is the squared value in L
        
        if the return value of the binary_search is more than or equal to 0, this means that the squared number is present in L
            if the index of the squared number is not equal to the current element we are checking
                we append returnArr with the number and its squared value

        counter + 1

    return returnArr
"""

import math


def find_pivot(list, low, high):
    pivot = list[high]
    i = low - 1

    for j in range(low, high):
        if list[j] <= pivot:
            i = i + 1
            (list[i], list[j]) = (list[j], list[i])

    (list[i + 1], list[high]) = (list[high], list[i + 1])

    return i + 1


def quick_sort(list, low, high):
    if low < high:
        pi = find_pivot(list, low, high)

        quick_sort(list, low, pi - 1)
        quick_sort(list, pi + 1, high)


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
        return -1


def main(list):
    quick_sort(list, 0, len(list)-1)

    returnArr = []
    i = 0

    while (i < len(list)):
        number = list[i]
        squared = number * number

        result = binary_search(list, squared)

        if (result >= 0):
            if (result != i):
                returnArr.append([number, squared])

        i += 1

    return returnArr


answer = main([16, 9, 4, 7, 8, 3, 2, 3])
print(answer)
answer = main([15, 2, 3, 6, 5, 1, 6, 7])
print(answer)
