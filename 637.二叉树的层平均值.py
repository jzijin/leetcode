#
# @lc app=leetcode.cn id=637 lang=python
#
# [637] 二叉树的层平均值
#
# https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
#
# algorithms
# Easy (56.55%)
# Total Accepted:    3.9K
# Total Submissions: 6.9K
# Testcase Example:  '[3,9,20,15,7]'
#
# 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
# 
# 示例 1:
# 
# 输入:
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 输出: [3, 14.5, 11]
# 解释:
# 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
# 
# 
# 注意：
# 
# 
# 节点值的范围在32位有符号整数范围内。
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
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        # averageOfLevels(root.left)        
        # averageOfLevels(root.left)

        # 关键是用队列来实现二叉树的层序遍历
        if root is None:
            return []
        target = []
        queue = []
        queue.append(root)
        while len(queue) > 0:
            tmp = len(queue)
            count = tmp
            total = 0.0
            while tmp > 0:
                next_node = queue.pop(0)
                total += next_node.val
                if next_node.left is not None:
                    queue.append(next_node.left)
                if next_node.right is not None:
                    queue.append(next_node.right)
                tmp -= 1
            target.append(total/count)
            # print(target)
        return target
        
        
        

