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
# class Solution(object):
#     def getMinimumDifference(self, root):
#         """
#         :type root: TreeNode
#         :rtype: int
#         """
#         target = []
#         self.getall(root, target)
#         cur = float('inf')
#         for i in range(0, len(target)):
#             for j in range(0, len(target)):
#                 if j== i:
#                     continue
#                 if abs(target[i] - target[j]) < cur:
#                     cur = abs(target[i] - target[j])
#         return cur

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 迭代实现中序遍历 
class Solution(object):
    def getminnum(self, root):
        """
        :rtype int get the minimal number
        """
        # 走左字数 左边的右子树是和根节点绝对值最小的树
        left = root.left
        while left is not None and left.right is not None:
            # 得到最右边的树
            left = left.right if left.right is not None else left.left
        # 走右子树 右子树的左子树是和根节点绝对值最小的树
        right = root.right
        while right is not None and right.left is not None:
            right = right.left if right.left is not None else right.right
        # print(right.val)
        if left is None and right is None:
            return float('inf')
        if left is None and right is not None:
            return right.val - root.val
        if left is not None and right is None:
            return root.val - left.val
        return min(root.val-left.val, right.val-root.val)

    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 存放最小绝对值差
        cur = float('inf')
        mystack = []
        while root is not None or len(mystack) > 0:
            while root is not None:
                mystack.append(root)
                root = root.left if root.left is not None else root.right
            root = mystack.pop()
            num = self.getminnum(root)
            if num < cur:
                cur = num
            # print(cur)
            if root.right is not None:
                root = root.right
            else:
                root = None    # 强迫退栈
            # print(root.val)
            # exit()
        # print(self.getminnum(root))
        return cur
        
        

