"""
@author: Shubham Dhumal
@description: This is demonstration program for Merge Sort sorting algorithm
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


def merge(input_list: list[int], start: int, q: int, end: int) -> None:
    """
    @input:
        @input_list: list of integers
        @start: index in input_list
        @q: index in input_list
        @end: index in input_list
    @output:
        None
    @postcondition:
        input_list[start...end] is sorted
    @precondition:
        1) 0 <= start <= q < end < len(input_list)
    """
    lst1_len = q - start + 1  # Size of sublist 1
    lst2_len = end - q        # Size of sublist 2
    sublist_1 = []
    sublist_2 = []

    # Step 1: Build 2 sub lists of sorted elements
    for i in range(0, lst1_len):
        sublist_1.append(input_list[start + i])

    for i in range(0, lst2_len):
        sublist_2.append(input_list[q + 1 + i])

    i = 0
    j = 0
    k = 0

    # Step 2: Merge two sub lists such that new list has elements in sorted order
    while True:
        if sublist_1[i] <= sublist_2[j]:
            input_list[start + k] = sublist_1[i]
            i = i + 1
            k = k + 1
            if i == lst1_len:
                while j < lst2_len:
                    input_list[start + k] = sublist_2[j]
                    j = j + 1
                    k = k + 1
                break
        else:
            input_list[start + k] = sublist_2[j]
            j = j + 1
            k = k + 1
            if j == lst2_len:
                while i < lst1_len:
                    input_list[start + k] = sublist_1[i]
                    i = i + 1
                    k = k + 1
                break


def merge_sort(input_list: list[int], start: int, end: int) -> None:
    if start < end:
        mid = (start + end) // 2
        merge_sort(input_list, start, mid)
        merge_sort(input_list, mid + 1, end)
        merge(input_list, start, mid, end)


def main():
    N = int(input("Enter the size of the list:(greater than 2):"))

    if N < 2:
        print("Bad size")
        sys.exit(-1)

    L = get_list(N)

    show_list(L, "Before sort:")

    merge_sort(L, 0, len(L) - 1)

    show_list(L, "After sort:")

    sys.exit(0)


if __name__ == '__main__':
    main()
