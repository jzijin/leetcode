#
# @lc app=leetcode.cn id=257 lang=python
#
# [257] 二叉树的所有路径
#
# https://leetcode-cn.com/problems/binary-tree-paths/description/
#
# algorithms
# Easy (56.96%)
# Total Accepted:    6.2K
# Total Submissions: 10.9K
# Testcase Example:  '[1,2,3,null,5]'
#
# 给定一个二叉树，返回所有从根节点到叶子节点的路径。
# 
# 说明: 叶子节点是指没有子节点的节点。
# 
# 示例:
# 
# 输入:
# 
# ⁠  1
# ⁠/   \
# 2     3
# ⁠\
# ⁠ 5
# 
# 输出: ["1->2->5", "1->3"]
# 
# 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
# 
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getpath(self, root, para, target):
        if root is None:
            target.append(para[2:])
            return 
        para = para + '->' + str(root.val)
        if root.left is None and root.right is None:
            target.append(para[2:])
        if root.left is not None:
            self.getpath(root.left, para, target)
        if root.right is not None:
            self.getpath(root.right, para, target)
        
        # return
        
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root is None:
            return []
        target = []
        self.getpath(root, '', target);
        return target
        
        
        

