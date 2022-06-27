from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

nums = list(map(int, input().strip().split()))
prev = None
head = ListNode()
for num in nums:
    if(prev):
        node = ListNode(num)
        prev.next = node
        prev = node
    else:
        head.val = num
        prev = head