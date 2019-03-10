#
# @lc app=leetcode.cn id=475 lang=python
#
# [475] 供暖器
#
# https://leetcode-cn.com/problems/heaters/description/
#
# algorithms
# Easy (26.35%)
# Total Accepted:    1.8K
# Total Submissions: 6.9K
# Testcase Example:  '[1,2,3]\n[2]'
#
# 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
# 
# 现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
# 
# 所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
# 
# 说明:
# 
# 
# 给出的房屋和供暖器的数目是非负数且不会超过 25000。
# 给出的房屋和供暖器的位置均是非负数且不会超过10^9。
# 只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
# 所有供暖器都遵循你的半径标准，加热的半径也一样。
# 
# 
# 示例 1:
# 
# 
# 输入: [1,2,3],[2]
# 输出: 1
# 解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
# 
# 
# 示例 2:
# 
# 
# 输入: [1,2,3,4],[1,4]
# 输出: 1
# 解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
# 
# 
#
class Solution:
    # TODO:二分查找缩短时间啊 切记切记不要傻乎乎的上来就暴力 太没意思了！！！！！！
    def findRadius(self, houses, heaters):
        def closest_heater(x, A = heaters, i = 0, j = len(heaters) - 1):
            if x < A[0] : return A[0]
            if A[-1] < x: return A[-1]
            while i <= j:
                mid = (i + j) // 2
                if x < A[mid]: 
                    j = mid - 1
                elif A[mid] < x: 
                    i = mid + 1
                else: 
                    return A[mid]
      # now i == j + 1
            return A[i] if A[i] - x < x - A[j] else A[j]
        
        heaters.sort()
        return max(abs(house - closest_heater(house)) for house in houses)
        

