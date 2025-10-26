class Bank:
    def __init__(self, b: List[int]):
        self.b = Counter(dict(enumerate([0]+b)))

    def transfer(self, a1: int, a2: int, m: int) -> bool:
        return self.withdraw(a1,m) and (self.deposit(a2,m) or not self.deposit(a1,m))

    def deposit(self, a: int, m: int) -> bool:
        return a<len(self.b) and not self.b.update({a:m})

    def withdraw(self, a: int, m: int) -> bool:
        return a<len(self.b) and self.b[a]>=m and not self.b.update({a:-m})