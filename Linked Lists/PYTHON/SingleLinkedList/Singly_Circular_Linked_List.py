from sys import exc_info

"""
@author:    Shubham Dhumal
@date:      15th June 24
@goal:      demonstrate implementation of singly circular linked list.
"""


class Node:
    def __init__(self, new_data: any):
        self.data = new_data
        self.next = None


class SinglyCircularLinkedList:
    def __init__(self):
        self.head_node = Node(None)
        self.head_node.next = self.head_node

    def insert_start(self, new_data: any) -> None:
        new_node = Node(new_data)
        new_node.next = self.head_node.next
        self.head_node.next = new_node

    def insert_end(self, new_data: any) -> None:
        run = self.head_node
        while run.next != self.head_node:
            run = run.next
        new_node = Node(new_data)
        new_node.next = run.next
        run.next = new_node

    def insert_after(self, e_data: any, new_data: any) -> None:
        run = self.head_node.next
        while run != self.head_node:
            if run.data == e_data:
                break
            run = run.next
        else:
            raise ValueError(f'Bad data:{e_data}')

        new_node = Node(new_data)
        new_node.next = run.next
        run.next = new_node

    def insert_before(self, e_data: any, new_data: any):
        run = self.head_node.next
        run_prev = self.head_node
        while run != self.head_node:
            if run.data == e_data:
                break
            run_prev = run
            run = run.next
        else:
            raise ValueError(f'Bad existing data:{e_data}')

        new_node = Node(new_data)
        new_node.next = run
        run_prev.next = new_node

    def get_start(self) -> any:
        if self.head_node.next == self.head_node:
            raise ValueError("List empty")
        return self.head_node.next.data

    def get_end(self) -> any:
        if self.head_node.next == self.head_node:
            raise ValueError("List empty")
        run = self.head_node
        while run.next != self.head_node:
            run = run.next
        return run.data

    def pop_start(self) -> any:
        if self.head_node.next == self.head_node:
            raise ValueError("List empty")
        data = self.head_node.next.data
        first_node_with_data = self.head_node.next
        self.head_node.next = first_node_with_data.next
        del first_node_with_data
        return data

    def pop_end(self) -> any:
        if self.head_node.next == self.head_node:
            raise ValueError("List empty")
        run = self.head_node.next
        run_prev = self.head_node
        while run.next != self.head_node:
            run_prev = run
            run = run.next
        data = run.data
        run_prev.next = self.head_node
        del run
        return data

    def remove_start(self) -> any:
        if self.head_node.next == self.head_node:
            raise ValueError("List empty")
        first_node_with_data = self.head_node.next
        self.head_node.next = first_node_with_data.next
        del first_node_with_data

    def remove_end(self) -> any:
        if self.head_node.next == self.head_node:
            raise ValueError("List empty")
        run = self.head_node.next
        run_prev = self.head_node
        while run.next != self.head_node:
            run_prev = run
            run = run.next
        run_prev.next = self.head_node
        del run

    def remove_data(self, r_data: any) -> any:
        run = self.head_node.next
        run_prev = self.head_node

        while run != self.head_node:
            if run.data == r_data:
                break
            run_prev = run
            run = run.next
        else:
            raise ValueError(f"bad value for {r_data}")

        run_prev.next = run.next
        del run

    def is_empty(self) -> bool:
        return self.head_node.next == self.head_node

    def show(self, msg=None) -> None:
        if msg is not None:
            print(msg)
        print("[START]->", end='')
        run = self.head_node.next
        while run != self.head_node:
            print(f'[{run.data}]->', end='')
            run = run.next
        print('[END]')

    def __len__(self) -> int:
        count = 0
        run = self.head_node.next
        while run != self.head_node:
            count += 1
            run = run.next
        return count

    def __contains__(self, find_data: any) -> bool:
        run = self.head_node.next
        while run != self.head_node:
            if run.data == find_data:
                return True
            run = run.next
        return False

    def __add__(self, other):
        new_list = SinglyCircularLinkedList()

        run = self.head_node.next
        while run != self.head_node:
            new_list.insert_end(run.data)
            run = run.next

        run = other.head_node.next
        while run is not other.head_node:
            new_list.insert_end(run.data)
            run = run.next
        return new_list

    def append(self, other):
        if other.head_node.next == other.head_node:
            del other.head_node
            return None

        run = self.head_node
        while run.next != self.head_node:
            run = run.next

        run.next = other.head_node.next

        run = other.head_node
        while run.next != other.head_node:
            run = run.next
        run.next = self.head_node

        del other.head_node
        return None

    def merge(self, other):
        sorted_list = SinglyCircularLinkedList()
        run_l1 = self.head_node.next
        run_l2 = other.head_node.next

        while run_l1 is not self.head_node and run_l2 is not other.head_node:
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
        while run_l1 is not self.head_node:
            sorted_list.insert_end(run_l1.data)
            run_l1 = run_l1.next

        while run_l2 is not other.head_node:
            sorted_list.insert_end(run_l2.data)
            run_l2 = run_l2.next

        return sorted_list


def main():
    L = SinglyCircularLinkedList()

    L.show()

    L.insert_end(10)
    L.insert_end(20)
    L.insert_end(30)
    L.insert_end(40)

    L.show("After insert_end()")

    L.insert_start(100)
    L.insert_start(200)
    L.insert_start(300)

    L.show("After isnert_start():")

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
        data = L.get_start()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'start_data:{data}')
    L.show("after get_start()")

    try:
        data = L.get_end()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'end_data:{data}')
    L.show("after get_end()")

    try:
        data = L.pop_start()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'start_data:{data}')
    L.show('after pop_start()')

    try:
        data = L.pop_end()
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

    n = len(L)
    print(f"length(L)=={n}")

    if 500 in L:
        print(f'500 is present in list')

    if -1 not in L:
        print("-1 is not present in list")

    L1 = SinglyCircularLinkedList()
    L2 = SinglyCircularLinkedList()

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
    L4 = SinglyCircularLinkedList()
    L5 = SinglyCircularLinkedList()

    for i in range(5):
        L4.insert_end(i * 5 - 2)

    for i in range(7):
        L5.insert_end(i * 10 - 5)

    L4.show("L4: ")
    L5.show("L5: ")
    L6 = L4.merge(L5)
    L6.show("L6: ")


if __name__ == '__main__':
    main()

