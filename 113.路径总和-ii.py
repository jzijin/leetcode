#
# @lc app=leetcode.cn id=113 lang=python
#
# [113] 路径总和 II
#
# https://leetcode-cn.com/problems/path-sum-ii/description/
#
# algorithms
# Medium (52.15%)
# Total Accepted:    6.2K
# Total Submissions: 11.7K
# Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
#
# 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
# 
# 说明: 叶子节点是指没有子节点的节点。
# 
# 示例:
# 给定如下二叉树，以及目标和 sum = 22，
# 
# ⁠             5
# ⁠            / \
# ⁠           4   8
# ⁠          /   / \
# ⁠         11  13  4
# ⁠        /  \    / \
# ⁠       7    2  5   1
# 
# 
# 返回:
# 
# [
# ⁠  [5,4,11,2],
# ⁠  [5,8,4,5]
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
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        mystack = [] # 这个是栈 用来保存结点的
        mystack2 = [] # 用来存放值
        target = [] # 用来返回
        # tmp = sum

        while root is not None or len(mystack) > 0:
            while root is not None:
                mystack.append(root)
                mystack2.append(root.val)
                if  root.val == sum and root.left is None and root.right is None:
                    aaa = mystack2[:]
                    target.append(aaa)
                sum -= root.val
                root = root.left if root.left is not None else root.right
            root = mystack.pop()
            mystack2.pop()
            sum += root.val
            if len(mystack) > 0 and mystack[-1].left == root:
                root = mystack[-1].right
            else:
                root = None
        return target

# 递归做法
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.res = []
        self.track = []
        self.helper(root, sum)
        return self.res

    def helper(self, node, sum):
        if not node:
            return
        self.track.append(node.val)
        sum -= node.val
        if not node.left and not node.right and sum == 0:
            self.res.append(self.track[:])
        else:
            # 往左边走
            self.helper(node.left, sum)
            # 往右边走
            self.helper(node.right, sum)
        self.track.pop()
                
        
        

