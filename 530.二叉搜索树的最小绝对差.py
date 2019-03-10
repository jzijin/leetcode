#
# @lc app=leetcode.cn id=530 lang=python
#
# [530] 二叉搜索树的最小绝对差
#
# https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
#
# algorithms
# Easy (51.56%)
# Total Accepted:    2.7K
# Total Submissions: 5.3K
# Testcase Example:  '[1,null,3,2]'
#
# 给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
# 
# 示例 :
# 
# 
# 输入:
# 
# ⁠  1
# ⁠   \
# ⁠    3
# ⁠   /
# ⁠  2
# 
# 输出:
# 1
# 
# 解释:
# 最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
# 
# 
# 注意: 树中至少有2个节点。
# 
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# TODO: 超时！！！！！
class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        target = []
        self.getall(root, target)
        cur = float('inf')
        for i in range(0, len(target)):
            for j in range(0, len(target)):
                if j== i:
                    continue
                if abs(target[i] - target[j]) < cur:
                    cur = abs(target[i] - target[j])
        return cur
        
        

