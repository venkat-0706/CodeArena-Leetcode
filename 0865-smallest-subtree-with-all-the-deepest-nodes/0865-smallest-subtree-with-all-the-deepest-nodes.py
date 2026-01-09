# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, r: Optional[TreeNode]) -> Optional[TreeNode]:
        def f(n):
            if not n: return 0,None
            ld,ln,rd,rn = *f(n.left),*f(n.right)
            return ((ld+1,n),(ld+1,ln),(rd+1,rn))[(ld>rd)-(ld<rd)]

        return f(r)[1]