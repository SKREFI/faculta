"""
Resurse:
https://en.wikipedia.org/wiki/Pairing_heap
https://www.geeksforgeeks.org/pairing-heap/
MIT OpenCourseWare - Heaps and Heap Sort

Implementare destul de minimalista, sincer m-am chinuit ceva cu el
Am scris putin cod de demonstrare, adica top (smallest element), delete si insert
"""


class Node():
    def __init__(self, value):
        self.value = value
        self.child = []

    def __repr__(self):
        ret = f'Node {self.value}'
        if not len(self.child) == 0:
            ret += f' childs: {self.child}'
        return ret


class PairingHeap():
    def __init__(self):
        self.root = None

    def top(self):
        return self.root.value if self.root is not None else None

    def merge(self, root, root2):
        if root is None:
            return root2
        if root2 is None:
            return root
        if root.value < root2.value:
            root.child.append(root2)
            return root
        root2.child.append(root)
        return root2

    def insert(self, value):
        self.root = self.merge(self.root, Node(value))

    def _merge_pairs(self, other):
        if len(other) == 0:
            return None
        if len(other) == 1:
            return other[0]
        return self.merge(self.merge(other[0], other[1]), self._merge_pairs(other[2:]))

    def delete(self):
        if self.root is not None:
            self.root = self._merge_pairs(self.root.child)


if __name__ == "__main__":
    h = PairingHeap()
    h.insert(1)
    h.insert(2)
    h.insert(3)

    h2 = PairingHeap()
    h2.insert(-10)
    h2.insert(11)
    h2.insert(12)
    h2.insert(15)

    h = h.merge(h.root, h2.root)  # nod practic

    print(h.child)

    print(h2.top())
    
    h2.delete()
    print(h2.top())
    h2.insert(-5)
    print(h2.top())
