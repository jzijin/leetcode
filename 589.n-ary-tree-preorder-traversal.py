#
# @lc app=leetcode.cn id=589 lang=python
#
# [589] N-ary Tree Preorder Traversal
#
# https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/
#
# algorithms
# Easy (65.62%)
# Total Accepted:    4.2K
# Total Submissions: 6.4K
# Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
#
# 给定一个 N 叉树，返回其节点值的前序遍历。
# 
# 例如，给定一个 3叉树 :
# 
# 
# 
# 
# 
# 
# 
# 返回其前序遍历: [1,3,5,6,2,4]。
# 
# 
# 
# 说明: 递归法很简单，你可以使用迭代法完成此题吗?
#
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder_(self, root, target):
        if root is None:
            return 
        target.append(root.val)
        for i in root.children:
            self.preorder_(i, target);
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        target = []
        self.preorder_(root, target)
        return target
    """
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
# class Solution(object):
#     def preorder(self, root):
#         """
#         :type root: Node
#         :rtype: List[int]
#         """
#         target = []
#         mystack= []
#         # print(root.children)
#         while root is not None or len(mystack) > 0:
#             while root is not None:
#                 target.append(root.val)
#                 length = len(root.children)
#                 while length-1 > 0:
#                     mystack.append(root.children[length-1])
#                     length -= 1
#                 if length > 0:
#                     root = root.children[0]
#                 else :
#                     root = None
#             if len(mystack) == 0:
#                 break
#             root = mystack.pop()
#         return target
        
        
        

