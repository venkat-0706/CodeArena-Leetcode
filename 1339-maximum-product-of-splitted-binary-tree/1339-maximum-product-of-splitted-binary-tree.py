# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.res = total = 0

        def s(root):
            if not root: return 0
            left, right = s(root.left), s(root.right)
            self.res = max(self.res, left * (total - left), right * (total - right))
            return left + right + root.val

        total = s(root)
        s(root)
        return self.res % (10**9 + 7)
        