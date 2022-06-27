from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        nums = []
        node = ListNode()
        node = head
        while node:
            nums.append(node.val)
            node = node.next

        node = head
        for num in reversed(nums):
            node.val = num
            node = node.next;

        return head

def main():
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

    s = Solution()
    res = s.reverseList(head)
    node = res
    while(node):
        print(node.val)
        node = node.next



if __name__ == "__main__":
    main()