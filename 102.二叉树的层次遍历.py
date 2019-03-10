#
# @lc app=leetcode.cn id=102 lang=python
#
# [102] 二叉树的层次遍历
#
# https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
#
# algorithms
# Medium (53.22%)
# Total Accepted:    17.2K
# Total Submissions: 32.1K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
# 
# 例如:
# 给定二叉树: [3,9,20,null,null,15,7],
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# 
# 返回其层次遍历结果：
# 
# [
# ⁠ [3],
# ⁠ [9,20],
# ⁠ [15,7]
# ]
# 
# 
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        target = []
        queue = []
        queue.append(root)
        l = []
        l.append(root.val)
        # print(queue)
        while len(queue) > 0:
            target.append(l)
            l = []
            tmp = len(queue)
            while tmp > 0:
                next_node = queue.pop(0)
                if next_node.left is not None:
                    queue.append(next_node.left)
                    l.append(next_node.left.val)
                if next_node.right is not None:
                    queue.append(next_node.right)
                    l.append(next_node.right.val)
                tmp -= 1
        return target
        
