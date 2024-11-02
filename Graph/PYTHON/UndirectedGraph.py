def geh(tb=False):
    from sys import exc_info
    from traceback import print_tb
    exc_name, exc_data, exc_tb = exc_info()
    print(exc_name.__name__, exc_data, sep=':')
    if tb:
        print_tb(exc_tb)


class VertexExistsError(Exception):
    pass


class VertexInvalidError(Exception):
    pass


class EdgeExistsError(Exception):
    pass


class EdgeInvalidError(Exception):
    pass


class GraphInconsistentError(Exception):
    pass


class color:
    WHITE = 1
    GREY = 2
    BLACK = 3


class glist_iterator:
    def __init__(self, generator):
        self.generator = generator

    def __iter__(self):
        return self

    def __next__(self):
        return self.generator.__next__()


# Data node of the horizontal linked list
class hnode:
    def __init__(self, vertex_number: int):
        self.v = vertex_number
        self.next = None
        self.prev = None


class hlist:

    @staticmethod
    def generic_insert(start: hnode, mid: hnode, end: hnode) -> None:
        mid.next = end
        mid.prev = start
        start.next = mid
        end.prev = mid

    @staticmethod
    def generic_delete(dnode: hnode) -> None:
        dnode.prev.next = dnode.next
        dnode.next.prev = dnode.prev

    def __init__(self):
        self.head_node = hnode(-1)
        self.head_node.prev = self.head_node
        self.head_node.next = self.head_node

    def search_node(self, vertex_number: int) -> hnode:
        run = self.head_node.next

        while run is not self.head_node:
            if run.v is vertex_number:
                return run
            run = run.next

        return None

    def insert_end(self, vertex_number: int) -> None:
        hlist.generic_insert(self.head_node.prev, hnode(vertex_number), self.head_node)

    def delete(self, vertex_number: int) -> None:
        hlist.generic_delete(self.search_node(vertex_number))

    def __contains__(self, item) -> bool:
        return self.search_node(item) is not None

    def __iter__(self):
        def get_generator(self):
            run = self.head_node.next
            while run is not self.head_node:
                yield run
                run = run.next

        return glist_iterator(get_generator(self))


# Data node of the vertical linked list
class vnode:
    def __init__(self, vertex_number: int):
        self.v = vertex_number
        self.adj_list = hlist()
        self.color = color.WHITE
        self.next = None
        self.prev = None


class vlist:

    @staticmethod
    def generic_insert(start: vnode, mid: vnode, end: vnode):
        mid.next = end
        mid.prev = start
        start.next = mid
        end.prev = mid

    @staticmethod
    def generic_delete(node_to_delete: vnode):
        node_to_delete.prev.next = node_to_delete.next
        node_to_delete.next.prev = node_to_delete.prev

    def __init__(self):
        self.head_node = vnode(-1)
        self.head_node.prev = self.head_node
        self.head_node.next = self.head_node

    def search_node(self, vertex_number: int) -> vnode:
        run = self.head_node.next

        while run is not self.head_node:
            if run.v is vertex_number:
                return run
            run = run.next

        return None

    def insert_end(self, vertex_number: int) -> None:
        vlist.generic_insert(self.head_node.prev, vnode(vertex_number), self.head_node)

    def delete(self, vertex_number: int) -> None:
        vlist.generic_delete(self.search_node(vertex_number))

    def __contains__(self, item) -> bool:
        return self.search_node(item) is not None

    def __iter__(self):
        def get_generator(self):
            run = self.head_node.next
            while run is not self.head_node:
                yield run
                run = run.next

        return glist_iterator(get_generator(self))


class UndirectedGraph:

    def __init__(self):
        self.vertices = vlist()
        self.nr_vertices = 0
        self.nr_edges = 0

    def add_vertex(self, vertex: int):
        if vertex in self.vertices:
            raise VertexExistsError(f"Vertex {vertex} already exists in graph.")

        self.vertices.insert_end(vertex)
        self.nr_vertices += 1

    def remove_vertex(self, vertex: int):
        vertex_to_delete_vnode = self.vertices.search_node(vertex)  # Find the vertex to delete
        if vertex_to_delete_vnode is None:  # Validate if vertex exists before trying to delete
            raise VertexInvalidError(f"Vertex {vertex} not found in graph.")

        # Now to delete to a vertex we need to delete it from vertices
        # and also from the adj_list of all other vertices which has edges to the vertex that we are deleting
        for vertex_hnode in vertex_to_delete_vnode.adj_list:
            vnode_of_adj_vertex = self.vertices.search_node(vertex_hnode.v)
            vnode_of_adj_vertex.adj_list.delete(vertex)
            self.nr_edges -= 1

        vlist.generic_delete(vertex_to_delete_vnode)

    def add_edge(self, u: int, v: int) -> None:
        # Validate if both vertex are valid
        if u not in self.vertices:
            raise VertexInvalidError(f"Vertex {u} doesn't exist in graph.")

        if v not in self.vertices:
            raise VertexInvalidError(f"Vertex {v} doesn't exist in graph.")

        start_vnode = self.vertices.search_node(u)
        end_vnode = self.vertices.search_node(v)

        u_exists_in_v_adj_list = u in end_vnode.adj_list
        v_exists_in_u_adj_list = v in start_vnode.adj_list

        # Validate if edge already exists between input vertices 'u' and 'v'
        if (u_exists_in_v_adj_list
                and v_exists_in_u_adj_list):
            raise EdgeExistsError(f"Edge ({u},{v}) already exists in graph.")

        if ((u_exists_in_v_adj_list and (not v_exists_in_u_adj_list))
                or (v_exists_in_u_adj_list and (not u_exists_in_v_adj_list))):
            raise GraphInconsistentError(f"Graph is corrupted")

        start_vnode.adj_list.insert_end(v)
        end_vnode.adj_list.insert_end(u)

        self.nr_edges += 1

    def remove_edge(self, u: int, v: int) -> None:
        # Validate if both vertex are valid
        if u not in self.vertices:
            raise VertexInvalidError(f"Vertex {u} doesn't exist in graph.")

        if v not in self.vertices:
            raise VertexInvalidError(f"Vertex {v} doesn't exist in graph.")

        start_vnode = self.vertices.search_node(u)
        end_vnode = self.vertices.search_node(v)

        u_not_exists_in_v_adj_list = u not in end_vnode.adj_list
        v_not_exists_in_u_adj_list = v not in start_vnode.adj_list

        # Validate if edge exists between input vertices 'u' and 'v'
        if (u_not_exists_in_v_adj_list
                and v_not_exists_in_u_adj_list):
            raise EdgeExistsError(f"Edge ({u},{v}) doesn't exists in graph. Cannot delete.")

        if ((u_not_exists_in_v_adj_list and (not v_not_exists_in_u_adj_list))
                or (v_not_exists_in_u_adj_list and (not u_not_exists_in_v_adj_list))):
            raise GraphInconsistentError(f"Graph is corrupted")

        start_vnode.adj_list.delete(v)
        end_vnode.adj_list.delete(u)

        self.nr_edges += 1

    def dfs(self, vertex_number: int):
        def reset():
            for vertex_vnode in self.vertices:
                vertex_vnode.color = color.WHITE

        def dfs_visit(u: vnode):
            print(f"[{u.v}]->", end='')
            u.color = color.GREY

            for adj_hnode in u.adj_list:
                v_adj_node = self.vertices.search_node(adj_hnode.v)
                if v_adj_node.color == color.WHITE:
                    dfs_visit(v_adj_node)

            u.color = color.BLACK

        reset()

        source_vertex_vnode = self.vertices.search_node(vertex_number)

        print("[START]->", end='')
        for adj_node in source_vertex_vnode.adj_list:
            v_adj_vnode = self.vertices.search_node(adj_node.v)
            if v_adj_vnode.color == color.WHITE:
                dfs_visit(v_adj_vnode)

        print("[END]")

    def bfs(self, vertex_number: int):
        def reset():
            for vertex_vnode in self.vertices:
                vertex_vnode.color = color.WHITE

        reset()

        source_vertex_vnode = self.vertices.search_node(vertex_number)

        if source_vertex_vnode is None:
            raise VertexInvalidError(f"Vertex {vertex_number} not found in graph.")

        print("[START]->", end='')

        q = [source_vertex_vnode]

        while len(q) != 0:
            vn = q.pop(0)
            vn.color = color.BLACK
            print(f'[{vn.v}]->', end='')
            for hn in vn.adj_list:
                h_in_vertices = self.vertices.search_node(hn.v)
                if h_in_vertices.color == color.WHITE and h_in_vertices not in q:
                    q.append(h_in_vertices)

        print("[END]")

    def __str__(self):
        op_string = f'|G.V|={self.nr_vertices}, |G.E|={self.nr_edges}\n'

        for vertex_vnode in self.vertices:
            op_string += f'[{vertex_vnode.v}]\t<->\t'
            for adjacent_hnode in vertex_vnode.adj_list:
                op_string += f'[{adjacent_hnode.v}]<->'
            op_string += '[END]\n'

        return op_string


def main():
    g = UndirectedGraph()
    vertices = [v for v in range(1, 7)]

    # Testing adding vertices
    for v in vertices:
        g.add_vertex(v)

    print(g)

    edges = [
        (1, 2), (2, 3), (3, 4),
        (4, 5), (5, 6), (6, 1),
        (2, 4), (2, 6), (3, 6),
        (3, 1)
    ]

    # Testing adding edges
    for (v_start, v_end) in edges:
        g.add_edge(v_start, v_end)

    print("g:initial state:\n", g)

    # BFS traversal
    for vertex in vertices:
        print(f"Traversing graph using BFS from source: {vertex}")
        g.bfs(vertex)

    print("")

    # DFS traversal
    for vertex in vertices:
        print(f"Traversing graph using DFS from source: {vertex}")
        g.dfs(vertex)

    # Test edge removal
    g.remove_edge(3, 4)
    g.remove_edge(2, 6)

    print("\ng:after removing (3, 4), (2, 6):\n", g)

    g.remove_vertex(2)

    print("g:after removing vertex 2:\n", g)


if __name__ == '__main__':
    main()
