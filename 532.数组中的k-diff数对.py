#
# @lc app=leetcode.cn id=532 lang=python
#
# [532] 数组中的K-diff数对
#
# https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/description/
#
# algorithms
# Easy (30.85%)
# Total Accepted:    3.1K
# Total Submissions: 10.1K
# Testcase Example:  '[3,1,4,1,5]\n2'
#
# 给定一个整数数组和一个整数 k, 你需要在数组里找到不同的 k-diff 数对。这里将 k-diff 数对定义为一个整数对 (i, j), 其中 i 和
# j 都是数组中的数字，且两数之差的绝对值是 k.
# 
# 示例 1:
# 
# 
# 输入: [3, 1, 4, 1, 5], k = 2
# 输出: 2
# 解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
# 尽管数组中有两个1，但我们只应返回不同的数对的数量。
# 
# 
# 示例 2:
# 
# 
# 输入:[1, 2, 3, 4, 5], k = 1
# 输出: 4
# 解释: 数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
# 
# 
# 示例 3:
# 
# 
# 输入: [1, 3, 1, 5, 4], k = 0
# 输出: 1
# 解释: 数组中只有一个 0-diff 数对，(1, 1)。
# 
# 
# 注意:
# 
# 
# 数对 (i, j) 和数对 (j, i) 被算作同一数对。
# 数组的长度不超过10,000。
# 所有输入的整数的范围在 [-1e7, 1e7]。
# 
# 
#

# TODO:像这种题目很多都是要用到 dic 或者 map的数据结构来统计的 切记切记
class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #1，首先利用map统计元素出现的频次key = num，value = 频次；2，遍历map统计 key + k 出现的次数（如果k == 0，统计的是 value > 1 这样的键值对的个数）。
        if k < 0:
            return 0
        dic = {}
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        # print(dic)
        res = 0
        for i in dic:
            if k:
                if i+k in dic and dic[i+k]:
                    res += 1
            else:
                if dic[i+k] > 1:
                    res += 1
        return res

        

