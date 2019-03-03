#
# @lc app=leetcode.cn id=590 lang=python
#
# [590] N-ary Tree Postorder Traversal
#
# https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/description/
#
# algorithms
# Easy (65.34%)
# Total Accepted:    3.7K
# Total Submissions: 5.6K
# Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
#
# 给定一个 N 叉树，返回其节点值的后序遍历。
# 
# 例如，给定一个 3叉树 :
# 
# 
# 
# 
# 
# 
# 
# 返回其后序遍历: [5,6,3,2,4,1].
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
    def postorder_(self, root, target):
        if root is None:
            return 
        for i in root.children:
            self.postorder_(i, target)
        target.append(root.val)
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        target = []
        self.postorder_(root, target)
        return target
        

