#
# @lc app=leetcode.cn id=606 lang=python
#
# [606] 根据二叉树创建字符串
#
# https://leetcode-cn.com/problems/construct-string-from-binary-tree/description/
#
# algorithms
# Easy (47.83%)
# Total Accepted:    2.4K
# Total Submissions: 5.1K
# Testcase Example:  '[1,2,3,4]'
#
# 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
#
# 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
#
# 示例 1:
#
#
# 输入: 二叉树: [1,2,3,4]
# ⁠      1
# ⁠    /   \
# ⁠   2     3
# ⁠  /
# ⁠ 4
#
# 输出: "1(2(4))(3)"
#
# 解释: 原本将是“1(2(4)())(3())”，
# 在你省略所有不必要的空括号对之后，
# 它将是“1(2(4))(3)”。
#
#
# 示例 2:
#
#
# 输入: 二叉树: [1,2,3,null,4]
# ⁠      1
# ⁠    /   \
# ⁠   2     3
# ⁠    \
# ⁠     4
#
# 输出: "1(2()(4))(3)"
#
# 解释: 和第一个示例相似，
# 除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
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

    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t:
            return ''
        left_str = '(' + self.tree2str(t.left) + ')' if t.left else None
        right_str = '(' + self.tree2str(t.right) + ')' if t.right else None
        if left_str and right_str:  # 如果叶子节点都不是None
            return str(t.val) + left_str + right_str
        if not left_str and right_str:  # 如果左子节点是None 那么应该加上一对括号
            return str(t.val) + '()' + right_str
        if left_str and not right_str:  # 如果右子节点是None 那么不需要加上括号
            return str(t.val) + left_str
        else:  # 如果叶子节点都不是None  那么直接返回
            return str(t.val)

        # if not t:
        #     return ""
        # res = str(t.val)
        # if t.left or t.right:
        #     res += "(" + self.tree2str(t.left) + ")"
        # if t.right:
        #     res += "(" + self.tree2str(t.right) + ")"
        # return res
