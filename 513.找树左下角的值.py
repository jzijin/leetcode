#
# @lc app=leetcode.cn id=513 lang=python
#
# [513] 找树左下角的值
#
# https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
#
# algorithms
# Medium (62.98%)
# Total Accepted:    2.1K
# Total Submissions: 3.4K
# Testcase Example:  '[2,1,3]'
#
# 给定一个二叉树，在树的最后一行找到最左边的值。
# 
# 示例 1:
# 
# 
# 输入:
# 
# ⁠   2
# ⁠  / \
# ⁠ 1   3
# 
# 输出:
# 1
# 
# 
# 
# 
# 示例 2: 
# 
# 
# 输入:
# 
# ⁠       1
# ⁠      / \
# ⁠     2   3
# ⁠    /   / \
# ⁠   4   5   6
# ⁠      /
# ⁠     7
# 
# 输出:
# 7
# 
# 
# 
# 
# 注意: 您可以假设树（即给定的根节点）不为 NULL。
# 
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
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
        #     print(l)
        # print(l)
        return target.pop()[0]
        

