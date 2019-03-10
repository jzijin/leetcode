#
# @lc app=leetcode.cn id=538 lang=python
#
# [538] 把二叉搜索树转换为累加树
#
# https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
#
# algorithms
# Easy (50.76%)
# Total Accepted:    2.6K
# Total Submissions: 5.1K
# Testcase Example:  '[5,2,13]'
#
# 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
# Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
# 
# 例如：
# 
# 
# 输入: 二叉搜索树:
# ⁠             5
# ⁠           /   \
# ⁠          2     13
# 
# 输出: 转换为累加树:
# ⁠            18
# ⁠           /   \
# ⁠         20     13
# 
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
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        pre = 0
        head = root
        mystack = []
        flag = 0
        if root is None:
            return root
        while True:
            # print("jdjdj")
            while head is not None:
                mystack.append(head)
                head = head.right
            # print(mystack)
            # exit()
            head = mystack.pop()
            head.val += pre
            pre = head.val
            if head.left is not None:
                # mystack.append(head)
                flag =1
                head = head.left
            else:
                flag =0
                head = None
            if len(mystack) == 0 and not flag:
                break
        return root
            
        

