# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getnums(self, root, target):
        if root is None:
            return 
        if root.left is None and root.right is None:
            target.append(root.val)
            return
        self.getnums(root.left, target)        
        self.getnums(root.right, target)

    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        target1 = []
        self.getnums(root1, target1)
        
        target2 = []
        self.getnums(root2, target2)
        # print(target)
        for i in range(0, len(target1)):
            if target1[i] != target2[i]:
                return False
        return True
        