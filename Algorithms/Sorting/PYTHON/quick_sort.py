"""
@author: Shubham Dhumal
@description: This is demonstration program for Quick Sort sorting algorithm
@date: 18th May 2024
"""
import sys


def get_list(list_size: int) -> list[int]:
    """
    @input:
        @list_size: positive integer -> expected size of list
    @output:
        Populates newly created list with @list_size random numbers
        stipulated between 0 and 1000
    """
    from random import randint

    if type(list_size) is not int:
        raise TypeError("N must be an int")
    if list_size <= 0:
        raise ValueError("N must be positive ")

    new_list = []

    starting_number = 0
    ending_number = 1001

    for i in range(list_size):
        new_list.append(randint(starting_number, ending_number))

    return new_list


def show_list(input_list: list[int], msg: str) -> None:
    """
    @input:
        @input_list: list of integers
        @msg: string message
    @output:
        Displays @msg along with @input_list on the standard output device
    """

    print(msg)
    for i in range(len(input_list)):
        print(f'L[{i}]:{input_list[i]}')


def partition(input_list: list[int], start: int, end: int) -> int:
    """
    @input:
        @input_list: non-empty list of integers
        @start: integer index in L
        @end: integer index in L
    @output:
        index q satisfying @postcondition
    @precondition:
        1) 0 <= start < end < len(L)
    @postcondition:
        1)  Element at L[end] should be moved to index q
            between [start, end] and rest of the elements
            should be re-arranged (permuted) such that

            i) all elements from L[start...q-1] are less than
            or equal to L[q]
            ii) all elements from L[q+1...end] are greater
            than L[q]
    """
    pivot = input_list[end]
    i = start - 1
    j = start

    while j < end:
        if input_list[j] <= pivot:
            i = i + 1
            input_list[i], input_list[j] = input_list[j], input_list[i]
        j = j + 1

    # Now Get pivot element to the middle of the list
    # such that all the elements to the left are <= pivot
    # and all on the right are > pivot
    input_list[end], input_list[i + 1] = input_list[i + 1], input_list[end]

    # And return the new position of pivot
    return i + 1


def quick_sort(input_list: list[int], start: int, end: int) -> None:
    if start < end:
        mid = partition(input_list, start, end)
        quick_sort(input_list, start, mid - 1)
        quick_sort(input_list, mid + 1, end)


def main():
    N = int(input("Enter the size of the list:(greater than 2):"))

    if N < 2:
        print("Bad size")
        sys.exit(-1)

    L = get_list(N)

    show_list(L, "Before sort:")

    quick_sort(L, 0, len(L) - 1)

    show_list(L, "After sort:")

    sys.exit(0)


if __name__ == '__main__':
    main()
