#
# @lc app=leetcode.cn id=447 lang=python
#
# [447] 回旋镖的数量
#
# https://leetcode-cn.com/problems/number-of-boomerangs/description/
#
# algorithms
# Easy (52.94%)
# Total Accepted:    2.9K
# Total Submissions: 5.5K
# Testcase Example:  '[[0,0],[1,0],[2,0]]'
#
# 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k
# 之间的距离相等（需要考虑元组的顺序）。
# 
# 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
# 
# 示例:
# 
# 
# 输入:
# [[0,0],[1,0],[2,0]]
# 
# 输出:
# 2
# 
# 解释:
# 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
# 
# 
#
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        2 6 12    
        """
        # 应该加一个哈希表 节省时间
        b=0
        for i in points:
           # s中保存所有到i距离相同的点的个数，键是距离
            s={}
            for j in points:
                a=(i[0]-j[0])**2+(i[1]-j[1])**2
                if a in s:
                    s[a]+=1
                else:
                    s[a]=1
            for k in s:
                if s[k]>1:
                    b+=s[k]*(s[k]-1) # TODO: 为什么是An2
        return b
        

