# Given the root of a binary tree and an integer targetSum, return true if the tree has root-to-leaf-
# path such that adding up all the values along the path equals targetSum

# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        # what if we are given an empty tree?
        if not root:
            return False
        # this
        flag = 0

        def dfs(root, pathSumSoFar):
            nonlocal flag
            # means we have not found the targetSum yet
            if flag == 0:
                if not root.left and not root.right:
                    pathSumSoFar += root.val
                    if targetSum == pathSumSoFar:
                        flag = 1
                    return
                if flag:
                    return
                if root.left:
                    dfs(root.left, pathSumSoFar + root.val)
                if root.right:
                    dfs(root.right, pathSumSoFar + root.val)
            return

        dfs(root, 0)
        return flag == 1
