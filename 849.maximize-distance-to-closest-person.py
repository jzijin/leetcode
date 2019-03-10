#
# @lc app=leetcode.cn id=849 lang=python
#
# [849] Maximize Distance to Closest Person
#
# https://leetcode-cn.com/problems/maximize-distance-to-closest-person/description/
#
# algorithms
# Easy (34.72%)
# Total Accepted:    2.7K
# Total Submissions: 7.9K
# Testcase Example:  '[1,0,0,0,1,0,1]'
#
# 在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。
# 
# 至少有一个空座位，且至少有一人坐在座位上。
# 
# 亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
# 
# 返回他到离他最近的人的最大距离。
# 
# 示例 1：
# 
# 输入：[1,0,0,0,1,0,1]
# 输出：2
# 解释：
# 如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
# 如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
# 因此，他到离他最近的人的最大距离是 2 。 
# 
# 
# 示例 2：
# 
# 输入：[1,0,0,0]
# 输出：3
# 解释： 
# 如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
# 这是可能的最大距离，所以答案是 3 。
# 
# 
# 提示：
# 
# 
# 1 <= seats.length <= 20000
# seats 中只含有 0 和 1，至少有一个 0，且至少有一个 1。
# 
# 
#
class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        cur = -1
        count = 0
        flag = 0
        for i in range(0, len(seats)):
            # flag = 0
            if seats[i] == 0:
                # 判断开头和结尾的边界条件
                if i == 0 or i==len(seats)-1:
                    flag = 1
                count += 1
            else:
                # print(count)
                # if count > cur:
                if flag:
                    flag = 0
                    if count > cur:
                        cur=count
                else:
                    if (count+1)/2 > cur:
                        cur = (count+1)/2
                # 重置count
                count = 0
        # 处理最后一个字符是0的情况
        if flag:
            flag = 0
            if count > cur:
                cur=count
        else:
            if (count+1)/2 > cur:
                cur = (count+1)/2
        return cur
            
        

