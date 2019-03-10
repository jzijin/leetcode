#
# @lc app=leetcode.cn id=812 lang=python
#
# [812] 旋转字符串
#
# https://leetcode-cn.com/problems/largest-triangle-area/description/
#
# algorithms
# Easy (54.74%)
# Total Accepted:    1.9K
# Total Submissions: 3.4K
# Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
#
# 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
# 
# 
# 示例:
# 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
# 输出: 2
# 解释: 
# 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
# 
# 
# 
# 
# 注意: 
# 
# 
# 3 <= points.length <= 50.
# 不存在重复的点。
# -50 <= points[i][j] <= 50.
# 结果误差值在 10^-6 以内都认为是正确答案。
# 
# 
#
class Solution(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        if len(A) == 0:
            return True
        tmp = len(A)
        while tmp:
            A = A[1:]+A[0:1]
            if A == B:
                return True
            tmp -= 1
        return False
#return len(A) == len(B) and B in A + A TODO: 什么骚操作！！！！
        

