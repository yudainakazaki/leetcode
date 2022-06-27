from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def traverse(self, node: Optional[TreeNode]):
        node.left, node.right = node.right, node.left
        if(node.left): 
            self.traverse(node.left)
        if(node.right):
            self.traverse(node.right)

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.traverse(root)
        return root