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
        if self.is_empty():
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
        if self.is_empty():
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
        if self.is_empty():
            raise ValueError("List is empty!! Cannot pop start")

        data = self.head_node.next.data
        self.head_node.next = self.head_node.next.next

        return data

    def pop_end(self) -> any:
        if self.is_empty():
            raise ValueError("List is empty!! Cannot pop end")

        run = self.head_node

        while run.next.next is not None:
            run = run.next

        data = run.next.data
        run.next = None

        return data

    def remove_start(self) -> None:
        if self.is_empty():
            raise ValueError("List is empty!! Cannot pop start")

        self.head_node.next = self.head_node.next.next

    def remove_end(self) -> None:
        if self.is_empty():
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
        if self.is_empty():
            raise ValueError("List is empty!! Cannot get start")

        return self.head_node.next.data

    def get_end(self) -> any:
        if self.is_empty():
            raise ValueError("List is empty!! Cannot get end")

        run = self.head_node

        while run.next is not None:
            run = run.next

        return run.data

    def is_empty(self) -> bool:
        return self.head_node.next is None

    def get_length(self) -> int:
        count = 0
        run = self.head_node.next

        while run is not None:
            count = count + 1
            run = run.next

        return count

    def show(self, msg: str = ''):
        if self.is_empty():
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
        print("\nLength: ", self.get_length())
        print("------------------------")


def main():
    L = SinglyLinkedList()

    L.insert_end(100)
    L.insert_end(200)
    L.insert_end(300)
    L.insert_end(400)

    L.show("After insert_end")

    L.insert_after(100, 20)

    L.show("After insert_after")

    L.insert_before(100, 30)

    L.show("After insert_before")

    data = L.pop_start()
    print(f'start: {data}')
    L.show("After pop_start")

    data = L.pop_end()
    print(f'end: {data}')
    L.show("After pop_end")

    L.insert_end(222)
    L.insert_end(300)

    print(f'get_start(): {L.get_start()}')

    print(f'get_end(): {L.get_end()}')


if __name__ == '__main__':
    main()