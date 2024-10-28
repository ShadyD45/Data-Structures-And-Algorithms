"""
@author: Shubham Dhumal
@goal: General implementation of RB Tree
@cmdline:
# python rb_tree N
where N is number of random integers to be inserted in tree
For reasonable output keep N <= 1000

Usage: script_name nr_elements
    nr_element: number of elements to insert in rb tree (These elements will be completely random)

if nr_elements is greater than 1000, then calculation and logging tree height after every insert/delete
will be disabled to save time and get accurate results of insert and remove ops

"""
import sys


class RotationNotPossibleException(Exception):
    pass


class Color:
    RED = 1
    BLACK = 2


class rb_node:
    def __init__(self, data: any = None, color: int = Color.RED, nil=None):
        self.data = data
        self.color = color
        self.left = nil
        self.right = nil
        self.parent = nil


class RedBlackTree:
    NIL = rb_node(color=Color.BLACK)  # Sentinel node
    # Pointing left, right of sentinel node to itself cause keeping them None
    # can cause failures when the data in tree increases
    NIL.left, NIL.right = NIL, NIL

    @staticmethod
    def _inorder(root_node: rb_node):
        if root_node is not RedBlackTree.NIL:
            RedBlackTree._inorder(root_node.left)
            print(f'[{root_node.data}]->', end='')
            RedBlackTree._inorder(root_node.right)

    @staticmethod
    def search_node(root_node: rb_node, s_data: int) -> rb_node:
        run = root_node
        while run is not RedBlackTree.NIL:
            if run.data == s_data:
                break
            elif s_data < run.data:
                run = run.left
            else:
                run = run.right
        return run

    @staticmethod
    def validate_left_rotation(tree_node: rb_node) -> None:
        if tree_node.right is RedBlackTree.NIL:
            raise RotationNotPossibleException(f"Left rotation around {tree_node.data} is not possible")

    @staticmethod
    def validate_right_rotation(tree_node: rb_node) -> None:
        if tree_node.left is RedBlackTree.NIL:
            raise RotationNotPossibleException(f"Right rotation around {tree_node.data} is not possible")

    @staticmethod
    def _height(root_node: rb_node) -> int:
        if root_node == RedBlackTree.NIL:
            return 0
        return max(RedBlackTree._height(root_node.left),
                   RedBlackTree._height(root_node.right)
                   ) + 1

    def __init__(self):
        self.root_node = None
        self.nr_elements = 0

    def inorder(self) -> None:
        print(f"[START]->", end='')
        RedBlackTree._inorder(self.root_node)
        print(f"[END]")

    def rb_transplant(self, u: rb_node, v: rb_node) -> None:
        if u.parent is RedBlackTree.NIL:
            self.root_node = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v

        if v is not RedBlackTree.NIL:
            v.parent = u.parent

    def _left_rotate(self, x: rb_node) -> None:
        y = x.right
        x.right = y.left

        if y.left is not RedBlackTree.NIL:
            y.left.parent = x

        y.parent = x.parent

        if x.parent == RedBlackTree.NIL:
            self.root_node = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y

        y.left = x
        x.parent = y

    def _right_rotate(self, x: rb_node) -> None:
        y = x.left
        x.left = y.right

        if y.right is not RedBlackTree.NIL:
            y.right.parent = x

        y.parent = x.parent

        if x.parent == RedBlackTree.NIL:
            self.root_node = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y

        y.right = x
        x.parent = y

    def rb_insert_fixup(self, z: rb_node):
        assert type(z) == rb_node, f"rb_insert_fixup:bad type {type(z)}"

        while z.parent.color == Color.RED:
            if z.parent is z.parent.parent.left:
                y = z.parent.parent.right
                if y.color == Color.RED:
                    z.parent.color = Color.BLACK
                    y.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    z = z.parent.parent
                else:
                    if z == z.parent.right:
                        z = z.parent
                        self._left_rotate(z)
                    z.parent.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    self._right_rotate(z.parent.parent)
            else:
                y = z.parent.parent.left
                if y.color == Color.RED:
                    z.parent.color = Color.BLACK
                    y.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    z = z.parent.parent
                else:
                    if z == z.parent.left:
                        z = z.parent
                        self._right_rotate(z)
                    z.parent.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    self._left_rotate(z.parent.parent)

        if self.root_node.color == Color.RED:
            self.root_node.color = Color.BLACK

    def rb_remove_fixup(self, x: rb_node) -> None:
        while x is not self.root_node and x.color == Color.BLACK:
            if x == x.parent.left:
                w = x.parent.right
                if w.color == Color.RED:
                    w.color = Color.BLACK
                    x.parent.color = Color.RED
                    self._left_rotate(x.parent)
                    w = x.parent.right
                if w is RedBlackTree.NIL:
                    x = x.parent
                    continue
                if w.left.color == Color.BLACK and w.right.color == Color.BLACK:
                    w.color = Color.RED
                    x = x.parent
                else:
                    if w.right.color == Color.BLACK:
                        w.left.color = Color.BLACK
                        w.color = Color.RED
                        self._right_rotate(w)
                        w = x.parent.right
                    w.color = x.parent.color
                    x.parent.color = Color.BLACK
                    w.right.color = Color.BLACK
                    self._left_rotate(x.parent)
                    x = self.root_node
            else:
                w = x.parent.left
                if w.color == Color.RED:
                    w.color = Color.BLACK
                    x.parent.color = Color.RED
                    self._right_rotate(x.parent)
                    w = x.parent.right
                if w is RedBlackTree.NIL:
                    x = x.parent
                    continue
                if w.left.color == Color.BLACK and w.right.color == Color.BLACK:
                    w.color = Color.RED
                    x = x.parent
                else:
                    if w.left.color == Color.BLACK:
                        w.right.color = Color.BLACK
                        w.color = Color.RED
                        self._left_rotate(w)
                        w = x.parent.left
                    w.color = x.parent.color
                    x.parent.color = Color.BLACK
                    w.left.color = Color.BLACK
                    self._right_rotate(x.parent)
                    x = self.root_node
        x.color = Color.BLACK

    def remove(self, n: int) -> None:
        z = RedBlackTree.search_node(self.root_node, n)
        if z is None:
            raise ValueError(f"data to be removed, {n}, does not exist")

        y = z
        y_original_color = y.color

        if z.left is RedBlackTree.NIL:
            x = z.right
            self.rb_transplant(z, z.right)
        elif z.right is RedBlackTree.NIL:
            x = z.left
            self.rb_transplant(z, z.left)
        else:
            y = z.right
            while y.left is not RedBlackTree.NIL:
                y = y.left
            y_original_color = y.color
            x = y.right
            if y.parent is z:
                x.parent = y
            else:
                self.rb_transplant(y, y.right)
                y.right = z.right
                y.right.parent = y
            self.rb_transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if y_original_color == Color.BLACK and x is not RedBlackTree.NIL:
            self.rb_remove_fixup(x)
        self.nr_elements -= 1

    def insert(self, new_data: int) -> None:
        z = rb_node(data=new_data, nil=RedBlackTree.NIL)

        if self.root_node is None:
            self.root_node = z
            self.rb_insert_fixup(z)
            self.nr_elements += 1
            return None

        run = self.root_node
        while True:
            if new_data <= run.data:
                if run.left is RedBlackTree.NIL:
                    run.left = z
                    z.parent = run
                    break
                else:
                    run = run.left
            else:
                if run.right is RedBlackTree.NIL:
                    run.right = z
                    z.parent = run
                    break
                else:
                    run = run.right
        self.rb_insert_fixup(z)
        self.nr_elements += 1
        return None

    def left_rotate(self, data: int):
        nd = self.search_node(self.root_node, data)

        if nd is None:
            raise ValueError(f"{data} not found in rb tree")

        RedBlackTree.validate_left_rotation(nd)

        RedBlackTree._left_rotate(nd)

    def right_rotate(self, data):
        nd = self.search_node(self.root_node, data)

        if nd is None:
            raise ValueError(f"{data} not found in rb tree")

        RedBlackTree.validate_right_rotation(nd)

        RedBlackTree._right_rotate(nd)

    def height(self):
        if self.root_node is RedBlackTree.NIL or self.root_node is None:
            return 0

        return RedBlackTree._height(self.root_node)

    def max_allowed_height(self):
        from math import floor, log2
        return 2 * floor(log2(self.get_nr_elements() + 1))

    def get_nr_elements(self):
        return self.nr_elements

    def __len__(self):
        return self.nr_elements


def main():
    from random import randint
    from sys import argv

    assert len(argv) == 2, "Usage: script_name nr_elements"

    test_data_size = int(argv[1])

    test_data = [randint(1, test_data_size * 10) for i in range(test_data_size)]

    rbt = RedBlackTree()

    for x in test_data:
        if test_data_size < 1000:  # For large input don't calculate and log height for each insert
            print(f"Current Height: {rbt.height()}, Max Allowed Height: {rbt.max_allowed_height()}")
        rbt.insert(x)

    print(f"*********** Tree state after inserting {test_data_size} elements **************")
    print(f"Current Height: {rbt.height()}, Max Allowed Height: {rbt.max_allowed_height()}")
    print("T.nr_elements:", len(rbt))

    if test_data_size < 1000:
        rbt.inorder()

    n_removed = 0
    for z in test_data:
        n_removed = n_removed + 1
        rbt.remove(z)
        if test_data_size < 1000:  # For large input don't calculate and log height for each delete
            print(f"Remaining Nodes: {test_data_size - n_removed}")
            print(f"Current Height: {rbt.height()}, Max Allowed Height: {rbt.max_allowed_height()}")

    print(
        f"********** Tree after deleting all elements:  "
        f"{rbt.height()}, Max Allowed Height: {rbt.max_allowed_height()} **********")

    if test_data_size < 1000:
        rbt.inorder()


if __name__ == '__main__':
    main()
