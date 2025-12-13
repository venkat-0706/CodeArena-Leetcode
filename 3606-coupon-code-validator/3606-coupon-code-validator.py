class Solution:
    def validateCoupons(self, code, businessLine, isActive):
        # Business line priority
        priority = {
            "electronics": 0,
            "grocery": 1,
            "pharmacy": 2,
            "restaurant": 3
        }

        # Check if coupon code is valid
        def is_valid_code(s):
            return len(s) > 0 and all(c.isalnum() or c == '_' for c in s)

        valid = []

        for i in range(len(code)):
            if (
                isActive[i] and
                businessLine[i] in priority and
                is_valid_code(code[i])
            ):
                valid.append((priority[businessLine[i]], code[i]))

        valid.sort()
        return [c for _, c in valid]