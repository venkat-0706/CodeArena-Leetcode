class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        curr = dummy
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            l1val = l1.val if l1 != None else 0
            l2val = l2.val if l2 != None else 0
            whole_sum = l1val + l2val + carry
            carry = whole_sum // 10
            newNode = ListNode(whole_sum % 10)
            curr.next = newNode                        
            curr = curr.next
            l1 = l1.next if l1 != None else l1
            l2 = l2.next if l2 != None else l2
        
        return dummy.next