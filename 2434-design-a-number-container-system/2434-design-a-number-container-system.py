from sortedcontainers import SortedList

class NumberContainers:

    def __init__(self):
        self.num_to_indices = defaultdict(SortedList)
        self.index_to_num = {}

    def change(self, index: int, number: int) -> None:
        if index in self.index_to_num:
            old = self.index_to_num[index]
            self.num_to_indices[old].discard(index)
            if not self.num_to_indices[old]:
                del self.num_to_indices[old]
        self.num_to_indices[number].add(index)
        self.index_to_num[index] = number
            

    def find(self, number: int) -> int:
        if number in self.num_to_indices:
            return self.num_to_indices[number][0]
        return -1