from sys import exc_info

"""
@author:    Shubham Dhumal
@date:      15th June 24
@goal:      To implement a package containing object-oriented
            implementation of doubly circular linked list.
"""


class List:
    class Node:
        def __init__(self, data: any):
            self.data = data
            self.prev = None
            self.next = None

    def __init__(self):
        self.head_node = self.Node(None)
        self.head_node.prev = self.head_node
        self.head_node.next = self.head_node

    @staticmethod
    def generic_insert(start_node, mid_node, end_node):
        mid_node.next = end_node
        mid_node.prev = start_node
        start_node.next = mid_node
        end_node.prev = mid_node

    @staticmethod
    def generic_delete(delete_node):
        delete_node.prev.next = delete_node.next
        delete_node.next.prev = delete_node.prev

    def search_node(self, s_data):
        run = self.head_node.next
        while run != self.head_node:
            if run.data == s_data:
                return run
            run = run.next

        return None

    def insert_start(self, new_data):
        List.generic_insert(
            self.head_node,
            List.Node(new_data),
            self.head_node.next
        )

    def insert_end(self, new_data):
        List.generic_insert(
            self.head_node.prev,
            List.Node(new_data),
            self.head_node
        )

    def insert_after(self, e_data, new_data):
        e_node = self.search_node(e_data)
        if e_node == None:
            raise ValueError(f'{e_data} is not present in list')
        List.generic_insert(
            e_node,
            List.Node(new_data),
            e_node.next
        )

    def insert_before(self, e_data, new_data):
        e_node = self.search_node(e_data)
        if e_node == None:
            raise ValueError(f'{e_data} is not present in list')
        List.generic_insert(
            e_node.prev,
            List.Node(new_data),
            e_node
        )

    def get_start(self):
        if self.empty():
            raise ValueError("cannot invoke get_start() on empty list")
        return self.head_node.next.data

    def get_end(self):
        if self.empty():
            raise ValueError("cannot invoke get_end() on emtpy list")
        return self.head_node.prev.data

    def pop_start(self):
        if self.empty():
            raise ValueError("Cannot invoke pop_start() on empty list")
        data = self.head_node.next.data
        List.generic_delete(self.head_node.next)
        return data

    def pop_end(self):
        if self.empty():
            raise ValueError("Cannot invoke pop_end() on empty list")
        data = self.head_node.prev.data
        List.generic_delete(self.head_node.prev)
        return data

    def remove_start(self):
        if self.empty():
            raise ValueError("Cannot invoke remove_start() on empty list")
        List.generic_delete(self.head_node.next)

    def remove_end(self):
        if self.empty():
            raise ValueError("Cannot invoke remove_end() on empty list")
        List.generic_delete(self.head_node.prev)

    def remove_data(self, r_data):
        r_node = self.search_node(r_data)
        if r_node == None:
            raise ValueError(f'{r_data} does not exist')
        List.generic_delete(r_node)

    def empty(self) -> bool:
        return (
                self.head_node.next == self.head_node and
                self.head_node.prev == self.head_node
        )

    def __len__(self):
        count = 0
        run = self.head_node.next
        while run != self.head_node:
            count = count + 1
            run = run.next
        return count

    def __contains__(self, data):
        node = self.search_node(data)
        return node is not None

    def __str__(self):
        op_str = '[START]<->'
        run = self.head_node.next
        while run != self.head_node:
            op_str = op_str + f'[{run.data}]<->'
            run = run.next
        op_str = op_str + '[END]\n'
        return op_str

    def __add__(self, other):
        new_list = List()

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
        if other.empty():
            del other.head_node
            return None
        # Append other list
        self.head_node.prev.next = other.head_node.next
        other.head_node.next.prev = self.head_node.prev  # set prev link after append

        # set last node of other links to the head_node of L1
        other.head_node.prev.next = self.head_node
        self.head_node.prev = other.head_node.prev

        del other.head_node
        return None

    def merge(self, other):
        sorted_list = List()
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

    def reverse(self):
        # List is empty or has less than 2 elements then do nothing
        if self.empty() or self.head_node.next.next is self.head_node:
            return None
        # [HEAD] <-> 10 <-> 20 <-> 30 <-> 40
        # [HEAD] <-> 20 <-> 10 <-> 30 <-> 40
        # [HEAD] <-> 30 <-> 20 <-> 10 <-> 40
        # [HEAD] <-> 40 <-> 30 <-> 20 <-> 10

        original_first = self.head_node.next
        run = self.head_node.next.next

        # Simple idea behind the solution is,
        # Iterate over the list and Keep moving
        # each node in the list to the first position,
        # This will eventually reverse the list.
        while run is not self.head_node:
            # Keep a reference to the next node,
            # so we can move ahead in the list later
            run_next = run.next
            # Then set the links for the run node
            # such that the node is set at the first position in list.
            run.prev = self.head_node
            run.next = self.head_node.next
            self.head_node.next.prev = run
            self.head_node.next = run
            # Move to next node in list
            run = run_next

        original_first.next = self.head_node
        self.head_node.prev = original_first

def main():
    print("UNIT TESTING START:")
    L = List()

    print("L:", L)

    L.insert_end(10)
    L.insert_end(20)
    L.insert_end(30)
    L.insert_end(40)

    print("After insert_end():", L)

    L.insert_start(100)
    L.insert_start(200)
    L.insert_start(300)

    print("After isnert_start():", L)

    L.insert_after(100, 500)
    L.insert_after(40, 50)

    print("After insert_after():", L)

    try:
        L.insert_after(-450, 1000)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    L.insert_before(50, 368)
    L.insert_before(100, 491)

    print("After insert_before():", L)

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
    print("after get_start():", L)

    try:
        data = L.get_end()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'end_data:{data}')
    print("after get_end():", L)

    try:
        data = L.pop_start()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'start_data:{data}')
    print('after pop_start():', L)

    try:
        data = L.pop_end()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)
    print(f'end_data:{data}')
    print('after pop_end():', L)

    try:
        data = L.remove_start()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print('after remove_start():', L)

    try:
        data = L.remove_end()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print('after remove_end():', L)

    try:
        data = L.remove_data(10)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print('after remove_data():', L)

    n = len(L)
    print(f"length(L)=={n}")

    ret = 500 in L
    if ret == True:
        print(f'500 is present in list')

    ret = -1 in L
    if ret == False:
        print("-1 is not present in list")

    L1 = List()
    L2 = List()

    for i in range(5):
        L1.insert_end(i * 5)
        L2.insert_end(i * 10)

    L3 = L1 + L2
    print(f"L1: {L1}")
    print(f"L2: {L2}")
    print(f"L1 + L2 = L3: {L3}")

    L1.append(L2)
    del L2
    print(f"L1: {L1}")

    print("************** MERGE LIST TEST *****************")
    L4 = List()
    L5 = List()

    for i in range(5):
        L4.insert_end(i * 5 - 2)

    for i in range(7):
        L5.insert_end(i * 10 - 5)

    print(f"L4: {L4}")
    print(f"L5: {L5}")

    L6 = L4 + L5
    print(f"L5: {L6}")

    L7 = List()
    print(f"L7: {L7}")

    for i in range(7):
        L7.insert_end(i * 10)

    L7.reverse()
    print(f"In place Reversed L7: {L7}")

    # Just test operations after reversing list inplace
    try:
        data = L7.pop_start()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'start_data:{data}')
    print(f'after pop_start() {L7}')

    try:
        data = L7.pop_end()
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)
    print(f'end_data:{data}')
    print(f'after pop_end() {L7}')

    try:
        data = L7.remove_data(20)
    except:
        exc_name, exc_data, _ = exc_info()
        print(exc_name, exc_data)

    print(f'after remove_data() {L7}')

    print("END OF UNIT TESTING")


if __name__ == '__main__':
    main()
