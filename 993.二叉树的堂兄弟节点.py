# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def find(self, root, last, val, k):
        if root is None:
            return 0
        if root.val == val:
            return [last, k]
        else:
            if self.find(root.left, root, val, k+1) == 0:
                return self.find(root.right, root, val, k+1)
            else:
                return self.find(root.left, root, val, k+1)
            
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        # print(self.find(root, None, x, 0), self.find(root, None, y, 0))
        # return self.find(root, None, x, 0) == self.find(root, None, y, 0)
        tmp1 = self.find(root, None, x, 0)
        tmp2 = self.find(root, None, y, 0)
        if tmp1[0] != tmp2[0] and tmp1[1] == tmp2[1]:
            return True
        return False
        