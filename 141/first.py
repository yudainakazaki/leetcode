from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head == None:
            return False
        slow = head
        fast = head
        while fast != None:
            if fast.next != None:
                fast = fast.next.next
            else:
                return False
            
            slow = slow.next
            if fast == slow:
                return True
            
        return False
        
def main():
    node0 = ListNode(3)
    node1 = ListNode(2)
    node2 = ListNode(0)
    node3 = ListNode(-4)
    node0.next = node1
    node1.next = node2
    node2.next = node3
    node3.next = node1
    
    node = node0
    s = Solution()
    result = s.hasCycle(node)
    print(result)
    
        
if __name__ == "__main__":
    main()
    