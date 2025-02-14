class ProductOfNumbers:
    def __init__(self):
        self.prefix_product = [1]
        self.size = 0

    def add(self, num: int):
        if num == 0:
            self.prefix_product = [1]
            self.size = 0
        else:
            self.prefix_product.append(self.prefix_product[self.size] * num)
            self.size += 1

    def getProduct(self, k: int) -> int:
        if k > self.size:
            return 0
        return (
            self.prefix_product[self.size] // self.prefix_product[self.size - k]
        )