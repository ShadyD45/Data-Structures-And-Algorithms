class EmptyTreeError(Exception):
    pass


class TreeNoSuccessor(Exception):
    pass


class TreeNoPredecessor(Exception):
    pass


class BstNode:
    def __init__(self, data: any):
        self.data = data
        self.left = None
        self.right = None
        self.parent = None

    def __str__(self):
        return f'data:{self.data}'


class BinarySearchTree:

    def __init__(self):
        self.root_node = None
        self.nr_elements = 0

    @staticmethod
    def search_node(root_node: BstNode, search_data: any):
        run = root_node
        while run is not None:
            if run.data == search_data:
                break
            elif search_data < run.data:
                run = run.left
            else:
                run = run.right
        return run

    @staticmethod
    def _inorder(r_node: BstNode):
        if r_node is not None:
            BinarySearchTree._inorder(r_node.left)
            print(f"[{r_node.data}]->", end='')
            BinarySearchTree._inorder(r_node.right)

    @staticmethod
    def _preorder(r_node: BstNode):
        if r_node is not None:
            print(f"[{r_node.data}]->", end='')
            BinarySearchTree._preorder(r_node.left)
            BinarySearchTree._preorder(r_node.right)

    @staticmethod
    def _postorder(r_node: BstNode):
        if r_node is not None:
            BinarySearchTree._postorder(r_node.left)
            BinarySearchTree._postorder(r_node.right)
            print(f"[{r_node.data}]->", end='')

    @staticmethod
    def inorder_successor_node(e_node: BstNode) -> BstNode:
        if e_node.right is not None:
            run = e_node.right
            while run.left is not None:
                run = run.left
            return run

        x = e_node
        y = x.parent
        while y is not None and x == y.right:
            x = y
            y = y.parent
        return y

    @staticmethod
    def inorder_predecessor_node(e_node: BstNode) -> BstNode:
        if e_node.left is not None:
            run = e_node.left
            while run.right is not None:
                run = run.right
            return run

        x = e_node
        y = x.parent
        while y is not None and x == y.left:
            x = y
            y = y.parent
        return y

    def insert(self, new_data: any):
        new_node = BstNode(new_data)

        if self.root_node is None:
            self.root_node = new_node
            self.nr_elements += 1
            return

        run = self.root_node

        while True:
            if new_data <= run.data:
                if run.left is None:
                    run.left = new_node
                    run.left.parent = run
                    break
                else:
                    run = run.left
            else:
                if run.right is None:
                    run.right = new_node
                    run.right.parent = run
                    break
                else:
                    run = run.right

        self.nr_elements += 1

    def remove(self, r_data: any):
        """
        @self: calling BST object
        @r_data: existing data to be dropped

        Remove a node containing @r_data from BST @self.
        Raise invalid_data exception if there is not node
        containing @r_data
        """
        node_to_remove = BinarySearchTree.search_node(self.root_node, r_data)
        if node_to_remove is None:
            raise ValueError(f"{r_data} : data to be removed is invalid")

        # Case 1: Node to remove doesn't have left subtree
        if node_to_remove.left is None:
            if node_to_remove.parent is None:  # Node to remove is root node in tree
                self.root_node = node_to_remove.right
            elif node_to_remove == node_to_remove.parent.left:  # node to remove is its parent left child
                node_to_remove.parent.left = node_to_remove.left
            else:  # node to remove is its parents right child
                node_to_remove.parent.right = node_to_remove.right

            if node_to_remove.right is not None:
                node_to_remove.right.parent = node_to_remove.parent

        elif node_to_remove.right is None:  # node to remove doesn't have right subtree
            if node_to_remove.parent is None:
                self.root_node = node_to_remove.left
            elif node_to_remove == node_to_remove.parent.left:
                node_to_remove.parent.left = node_to_remove.left
            else:
                node_to_remove.parent.right = node_to_remove.left

            node_to_remove.left.parent = node_to_remove.parent

        elif node_to_remove is not None and node_to_remove.right is not None:
            # Node to remove has both left and right subtrees
            y = node_to_remove.right
            while y.left is not None:
                y = y.left

            if y != node_to_remove.right:
                y.parent.left = y.right  # !!
                if y.right is not None:
                    y.right.parent = y.parent
                y.right = node_to_remove.right
                y.right.parent = y

            y.left = node_to_remove.left
            y.left.parent = y

            if node_to_remove.parent is None:
                self.root_node = y
            elif node_to_remove is node_to_remove.parent.left:
                node_to_remove.parent.left = y
            else:
                node_to_remove.parent.right = y

            y.parent = node_to_remove.parent

    def search(self, search_data: any):
        run = self.root_node
        while run is not None:
            if search_data == run.data:
                return True
            elif search_data < run.data:
                run = run.left
            else:
                run = run.right
        return False

    def inorder(self):
        print("[START]->", end='')
        BinarySearchTree._inorder(self.root_node)
        print("[END]")

    def preorder(self):
        print("[START]->", end='')
        BinarySearchTree._preorder(self.root_node)
        print("[END]")

    def postorder(self):
        print("[START]->", end='')
        BinarySearchTree._postorder(self.root_node)
        print("[END]")

    def level_order(self):
        Q = [self.root_node]
        print("[START]->")
        while len(Q) != 0:
            bst_node = Q.pop(0)
            print(f"[{bst_node.data}]->",end='')
            if bst_node.left is not None:
                Q.append(bst_node.left)
            if bst_node.right is not None:
                Q.append(bst_node.right)
        print("[END]")

    def min(self):
        if self.root_node is None:
            raise EmptyTreeError("Cannot find min in empty tree")
        run = self.root_node
        while run.left is not None:
            run = run.left
        return run.data

    def max(self):
        if self.root_node is None:
            raise EmptyTreeError("Cannot find max in empty tree")
        run = self.root_node
        while run.right is not None:
            run = run.right
        return run.data

    def inorder_predecessor(self, e_data: any) -> any:
        """
        @self: calling BST object
        @e_data: existing data value in BST
        @return: data value in a predecessor node of the node
        containing @e_data while traversing BST @self using
        inorder sequence
        @exceptions:
        invalid_data: if e_data is not found
        inorder_no_predecessor: if @e_data is the min data in BST @self
        """
        e_node = BinarySearchTree.search_node(self.root_node, e_data)
        if e_node is None:
            raise ValueError("bad value for existing data")
        pred_node = BinarySearchTree.inorder_predecessor_node(e_node)
        if pred_node is not None:
            return pred_node.data
        else:
            raise TreeNoPredecessor("Max data has no predecessor")

    def inorder_successor(self, e_data: any) -> any:
        """
        @self: calling BST object
        @e_data: existing data value in BST
        @return: data value in a successor node of the node
        containing @e_data while traversing BST @self using
        inorder sequence
        @exceptions:
        invald_data: if e_data is not found
        inorder_no_successor: if @e_data is the max data in BST @self
        """
        e_node = BinarySearchTree.search_node(self.root_node, e_data)
        if e_node is None:
            raise ValueError("bad value for existing data")
        succ_node = BinarySearchTree.inorder_successor_node(e_node)
        if succ_node is not None:
            return succ_node.data
        else:
            raise TreeNoSuccessor("Max data has no successor")


def main():
    test_data = [100, 50, 150, 25, 75, 125, 200,
                 15, 17, 130, 135]

    T = BinarySearchTree()

    for x in test_data:
        T.insert(x)

    print("INORDER:")
    T.inorder()

    print("PREORDER:")
    T.preorder()

    print("POSTORDER:")
    T.postorder()

    T = BinarySearchTree()
    L = [100, 50, 150, 40, 60, 200, 55, 70, 175, 250,
         80, 160, 180, 225, 275, 158, 210, 155, 156]
    for x in L:
        T.insert(x)

    print("Printing new tree in inorder sequence:")
    T.inorder()

    succ_data = T.inorder_successor(150)
    print("SUCC of 150:", succ_data)

    succ_data = T.inorder_successor(80)
    print("SUCC of 80:", succ_data)

    try:
        for x in sorted(L):
            succ_data = T.inorder_successor(x)
            print(f'SUCC({x}) == {succ_data}')
    except TreeNoSuccessor:
        print(f"Max data:{x} has no successor")

    try:
        for x in sorted(L, reverse=True):
            pred_data = T.inorder_predecessor(x)
            print(f'PRED({x}) == {pred_data}')
    except TreeNoPredecessor:
        print(f"Max data:{x} has no predecessor")

    print("LEVEL ORDER:")
    T.level_order()

    from random import shuffle
    LC = L.copy()
    shuffle(LC)
    for x in LC:
        print(f"Removing {x} from T")
        T.remove(x)


if __name__ == '__main__':
    main()