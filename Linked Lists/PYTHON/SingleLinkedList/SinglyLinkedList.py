from sys import exc_info

"""
@author: Shubham Dhumal
@goal: To implement and test singly linked list data structure
"""


class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head_node = Node(None)

    def insert_end(self, new_data):
        new_node = Node(new_data)
        start = self.head_node

        while start.next is not None:
            start = start.next

        start.next = new_node

    def insert_start(self, new_data: any) -> bool:
        new_node = Node(new_data)
        new_node.next = self.head_node.next
        self.head_node.next = new_node

    def insert_after(self, existing_data: any, new_data: any) -> bool:
        if self.empty():
            raise IndexError("List is empty")

        run = self.head_node

        while run is not None:
            if run.data == existing_data:
                break
            run = run.next
        else:
            raise ValueError("Given data not found in list")

        new_node = Node(new_data)  # Create new node
        # Adjust Links
        new_node.next = run.next
        run.next = new_node

        return True

    def insert_before(self, existing_data: any, new_data: any) -> bool:
        if self.empty():
            return False

        run = self.head_node

        while run.next is not None:
            if run.next.data == existing_data:
                break
            run = run.next
        else:
            raise ValueError("Given data not found in list")

        new_node = Node(new_data)  # Create Node
        # Adjust links
        new_node.next = run.next
        run.next = new_node

        return True

    def pop_start(self) -> any:
        if self.empty():
            raise ValueError("List is empty!! Cannot pop start")

        data = self.head_node.next.data
        self.head_node.next = self.head_node.next.next

        return data

    def pop_end(self) -> any:
        if self.empty():
            raise ValueError("List is empty!! Cannot pop end")

        run = self.head_node

        while run.next.next is not None:
            run = run.next

        data = run.next.data
        run.next = None

        return data

    def remove_start(self) -> None:
        if self.empty():
            raise ValueError("List is empty!! Cannot pop start")

        self.head_node.next = self.head_node.next.next

    def remove_end(self) -> None:
        if self.empty():
            raise ValueError("List is empty!! Cannot pop end")

        run = self.head_node

        while run.next.next is not None:
            run = run.next

        run.next = run.next.next

    def remove_data(self, r_data: any) -> None:
        run = self.head_node

        while run.next is not None and run.next.data != r_data:
            run = run.next

        run.next = run.next.next

    def get_start(self) -> any:
        if self.empty():
            raise ValueError("List is empty!! Cannot get start")

        return self.head_node.next.data

    def get_end(self) -> any:
        if self.empty():
            raise ValueError("List is empty!! Cannot get end")

        run = self.head_node

        while run.next is not None:
            run = run.next

        return run.data

    def length(self) -> int:
        count = 0
        run = self.head_node.next

        while run is not None:
            count = count + 1
            run = run.next

        return count

    def find(self, f_data):
        run = self.head_node.next
        while run is not None:
            if run.data == f_data:
                break
            run = run.next
        else:
            return False
        return True

    def show(self, msg: str = ''):
        if self.empty():
            print("List is empty")
            return

        print(f'{msg} : List is: [START] ->', end=' ')

        i = 0
        run = self.head_node.next

        while run is not None:
            print(f'L[{i}]:{run.data} -> ', end='')
            run = run.next
            i = i + 1

        print("[END]", end=' ')
        print("\nLength: ", self.length())
        print("------------------------")

    def empty(self):
        return self.head_node.next is None

    def __add__(self, other):
        new_list = SinglyLinkedList()
        run = self.head_node.next

        while run is not None:
            new_list.insert_end(run.data)
            run = run.next

        run = other.head_node.next

        while run is not None:
            new_list.insert_end(run.data)
            run = run.next

        return new_list

    def append(self, other):
        # if L2 is empty, then there id nothing to do
        if other.empty():
            del other.head_node
            return None

        # if L2 is not empty then find out the last
        # node of L1. If L1 is empty the last node
        # is head_node otherwise last node contaianing
        # data object is the last node
        run = self.head_node

        while run.next is not None:
            run = run.next

        # attach first node with data in L2
        # with the last node in L1
        run.next = other.head_node.next
        del other.head_node

    def merge(self, other):
        sorted_list = SinglyLinkedList()
        run_l1 = self.head_node.next
        run_l2 = other.head_node.next

        while run_l1 is not None and run_l2 is not None:
            if run_l1.data == run_l2.data:
                sorted_list.insert_end(run_l1.data)
                sorted_list.insert_end(run_l2.data)
                run_l1 = run_l1.next
                run_l2 = run_l2.next
            elif run_l1.data < run_l2.data:
                sorted_list.insert_end(run_l1.data)
                run_l1 = run_l1.next
            else:
                sorted_list.insert_end(run_l2.data)
                run_l2 = run_l2.next

        # If anything remaining in one of the list just insert at the end of sorted list
        while run_l1 is not None:
            sorted_list.insert_end(run_l1.data)
            run_l1 = run_l1.next

        while run_l2 is not None:
            sorted_list.insert_end(run_l2.data)
            run_l2 = run_l2.next

        return sorted_list

    def get_reversed_list(self):
        new_list = SinglyLinkedList()
        run = self.head_node.next
        while run is not None:
            new_list.insert_start(run.data)
            run = run.next
        return new_list

    def reverse(self):
        if self.head_node.next is None or self.head_node.next.next is None:
            return None

        # 10 -> 20 -> 30 -> 40
        # 20 -> 10 -> 30 -> 40
        # 30 -> 20 -> 10 -> 40
        # 40 -> 30 -> 20 -> 10

        original_first = self.head_node.next
        run = self.head_node.next.next

        while run is not None:
            run_next = run.next
            run.next = self.head_node.next
            self.head_node.next = run
            run = run_next

        original_first.next = None


def main():
    L = SinglyLinkedList()

    L.show()  # [START]->[END]

    L.insert_end(10)
    L.insert_end(20)
    L.insert_end(30)
    L.insert_end(40)

    L.show("After insert_end()")  # [START]->[10]->[20]->[30]->[40]->[END]

    L.insert_start(100)
    L.insert_start(200)
    L.insert_start(300)

    L.show("After isnert_start():")  # [START]->[300]->[200]->[100]->[10]->[20]->[30]->[40]->[END]

    L.insert_after(100, 500)
    L.insert_after(40, 50)

    L.show("After insert_after():")

    try:
        L.insert_after(-450, 1000)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    L.insert_before(50, 368)
    L.insert_before(100, 491)

    L.show("After insert_before():")

    try:
        L.insert_before(-450, 1000)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    try:
        data = L.get_start()  # SinglyLinkedList.get_start(L)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'start_data:{data}')
    L.show("after get_start()")

    try:
        data = L.get_end()  # SinglyLinkedList.get_end(L)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'end_data:{data}')
    L.show("after get_end()")

    try:
        data = L.pop_start()  # SinglyLinkedList.pop_start(L)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'start_data:{data}')
    L.show('after pop_start()')

    try:
        data = L.pop_end()  # SinglyLinkedList.pop_end(L)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)
    print(f'end_data:{data}')
    L.show('after pop_end()')

    try:
        data = L.remove_start()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    L.show('after remove_start()')

    try:
        data = L.remove_end()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    L.show('after remove_end()')

    try:
        data = L.remove_data(10)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    L.show('after remove_data()')

    n = L.length()
    print(f"length(L)=={n}")

    ret = L.find(500)
    if ret == True:
        print(f'500 is present in list')

    ret = L.find(-1)
    if ret == False:
        print("-1 is not present in list")

    L1 = SinglyLinkedList()
    L2 = SinglyLinkedList()

    for i in range(5):
        L1.insert_end(i * 5)
        L2.insert_end(i * 10)

    L3 = L1 + L2
    L1.show("L1: ")
    L2.show("L2: ")
    L3.show("L1 + L2 = L3: ")

    L1.append(L2)
    del L2
    L1.show("L1: ")

    print("************** MERGE LIST TEST *****************")
    L4 = SinglyLinkedList()
    L5 = SinglyLinkedList()

    for i in range(5):
        L4.insert_end(i * 5 - 2)

    for i in range(7):
        L5.insert_end(i * 10 - 5)

    L4.show("L4: ")
    L5.show("L5: ")
    L6 = L4.merge(L5)
    L6.show("L6: ")

    L6.reverse()
    L6.show(f"L6 reverse: ")


if __name__ == '__main__':
    main()
