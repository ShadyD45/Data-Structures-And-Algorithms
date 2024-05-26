from sys import exc_info

"""
@author: Shubham Dhumal
@date: 26th May 2024
@goal: Implementing doubly linked list
"""


class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head_node = Node(None)

    def insert_start(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head_node.next
        new_node.prev = self.head_node
        # In case list is empty we only need to insert new node so skip the prev
        if self.head_node.next is not None:
            self.head_node.next.prev = new_node
        self.head_node.next = new_node

    def insert_end(self, new_data):
        run = self.head_node

        while run.next is not None:
            run = run.next

        new_node = Node(new_data)
        new_node.prev = run
        run.next = new_node

    def insert_after(self, e_data, new_data):
        run = self.head_node.next

        while run is not None:
            if run.data == e_data:
                break
            run = run.next
        else:
            raise ValueError(f"{e_data} not found in list")

        new_node = Node(new_data)
        new_node.next = run.next
        new_node.prev = run
        # In case the existing node is at the last we need to skip prev
        if run.next is not None:
            run.next.prev = new_node
        run.next = new_node

    def insert_before(self, e_data, new_data):
        run = self.head_node.next
        while run is not None:
            if run.data == e_data:
                break
            run = run.next
        else:
            raise ValueError("Data not found in list")

        new_node = Node(new_data)

        new_node.next = run
        new_node.prev = run.prev
        run.prev.next = new_node
        run.prev = new_node

    def get_start(self) -> any:
        if self.head_node.next is None and self.head_node.prev is None:
            raise ValueError("List is empty")
        return self.head_node.next.data

    def get_end(self) -> any:
        if self.head_node.next is None and self.head_node.prev is None:
            raise ValueError("List is empty")
        run = self.head_node
        while run.next is not None:
            run = run.next
        return run.data

    def pop_start(self) -> any:
        if self.head_node.next is None and self.head_node.prev is None:
            raise ValueError("List is empty")

        data = self.head_node.next.data
        r_node = self.head_node.next

        if r_node.next is not None:
            r_node.next.prev = r_node.prev

        r_node.prev.next = r_node.next

        del r_node

        return data

    def pop_end(self) -> any:
        if self.head_node.next is None and self.head_node.prev is None:
            raise ValueError("List is empty")

        run = self.head_node
        while run.next is not None:
            run = run.next
        data = run.data
        run.prev.next = None
        del run
        return data

    def remove_start(self):
        if self.is_empty():
            raise ValueError("List is empty")

        r_node = self.head_node.next

        if r_node.next is not None:
            r_node.next.prev = r_node.prev
        r_node.prev.next = r_node.next
        del r_node

    def remove_end(self):
        if self.is_empty():
            raise ValueError("List is empty")
        run = self.head_node
        while run is not None:
            run = run.next
        run.prev.next = None
        del run

    def remove_data(self, r_data):
        run = self.head_node.next
        while run is not None:
            if run.data == r_data:
                break
            run = run.next
        else:
            ValueError(f"{r_data} not found in list")

        run.prev.next = run.next
        if run.next is not None:
            run.next.prev = run.prev
        del run

    def find(self, f_data) -> any:
        run = self.head_node.next
        while run is not None:
            if run.data == f_data:
                break
            run = run.next
        else:
            return False
        return True

    def is_empty(self) -> bool:
        return self.head_node.next is None and self.head_node.prev is None

    def length(self) -> int:
        count = 0
        run = self.head_node.next

        while run is not None:
            count = count + 1
            run = run.next

        return count

    def show(self, msg: str = ''):
        if self.head_node.next is None:
            print("List is empty")
            return

        print(f'{msg} List is: [START] <->', end=' ')

        i = 0
        run = self.head_node.next

        while run is not None:
            print(f'L[{i}]:[{run.data}] <-> ', end='')
            run = run.next
            i = i + 1

        print("[END]")


def main():
    L = DoublyLinkedList()

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
    if ret:
        print(f'500 is present in list')

    ret = L.find(-1)
    if ret == False:
        print("-1 is not present in list")

    """
    linked list empty == no node with data == (self.head_node.next == None)
    linked list not empty == at least one node with data == 
    (self.head_node.next == first node with data)
    """


if __name__ == '__main__':
    main()
