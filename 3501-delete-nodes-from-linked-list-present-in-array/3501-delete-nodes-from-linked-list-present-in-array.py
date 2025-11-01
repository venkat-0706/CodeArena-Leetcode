class Solution(object):
    def modifiedList(self, nums, head):
        mpp = set(nums)
        while head and head.val in mpp:
            head = head.next
        curr = head
        while curr and curr.next:
            while curr.next and curr.next.val in mpp:
                curr.next = curr.next.next
            curr = curr.next
        return head