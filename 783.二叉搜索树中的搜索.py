#
# @lc app=leetcode.cn id=783 lang=python
#
# [783] 二叉搜索树中的搜索
#
# https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
#
# algorithms
# Easy (51.00%)
# Total Accepted:    1.9K
# Total Submissions: 3.7K
# Testcase Example:  '[4,2,6,1,3,null,null]'
#
# 给定一个二叉搜索树的根结点 root, 返回树中任意两节点的差的最小值。
# 
# 示例：
# 
# 
# 输入: root = [4,2,6,1,3,null,null]
# 输出: 1
# 解释:
# 注意，root是树结点对象(TreeNode object)，而不是数组。
# 
# 给定的树 [4,2,6,1,3,null,null] 可表示为下图:
# 
# ⁠         4
# ⁠       /   \
# ⁠     2      6
# ⁠    / \    
# ⁠   1   3  
# 
# 最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
# 
# 注意：
# 
# 
# 二叉树的大小范围在 2 到 100。
# 二叉树总是有效的，每个节点的值都是整数，且不重复。
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
    def getnums(self, root, target):
        if root is None:
            return 
        target.append(root.val)
        self.getnums(root.left, target)        
        self.getnums(root.right, target)

    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        target = []
        self.getnums(root, target)
        target.sort()
        num = float("inf")
        return min([target[i+1]-target[i] for i in range(len(target)-1)])
#         mystack = []
#         cur = float("inf")
#         while root is not None or len(mystack) > 1:
#             while root is not None:
#                 # print(root.val)
#                 mystack.append(root.right)
#                 if root.left is not None:
#                     tmp = root.val-root.left.val
#                     if tmp < cur:
#                         cur = tmp
#                 if root.right is not None:
#                     # print(root.right.val)
#                     tmp = root.right.val -root.val
#                     if tmp < cur:
#                         cur = tmp
#                     mystack.append(root.right)
                
                
#                 # print(mystack)
#                 root = root.left
#             if len(mystack) == 0:
#                 break
#             root = mystack.pop()
            
#         return cur
    
            
        
        

