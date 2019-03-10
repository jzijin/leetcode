#
# @lc app=leetcode.cn id=697 lang=python
#
# [697] 数组的度
#
# https://leetcode-cn.com/problems/degree-of-an-array/description/
#
# algorithms
# Easy (44.55%)
# Total Accepted:    2.8K
# Total Submissions: 6.3K
# Testcase Example:  '[1,2,2,3,1]'
#
# 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
# 
# 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
# 
# 示例 1:
# 
# 
# 输入: [1, 2, 2, 3, 1]
# 输出: 2
# 解释: 
# 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
# 连续子数组里面拥有相同度的有如下所示:
# [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
# 最短连续子数组[2, 2]的长度为2，所以返回2.
# 
# 
# 示例 2:
# 
# 
# 输入: [1,2,2,3,1,4,2]
# 输出: 6
# 
# 
# 注意:
# 
# 
# nums.length 在1到50,000区间范围内。
# nums[i] 是一个在0到49,999范围内的整数。
# 
# 
#

# 1.统计次数---HashMap 2.记录左右索引---HashMap 3.找到次数最多的数 4.其相对左右索引差值的最小
class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # return 1
        nums_freq = {}
        for i in nums:
            if i in nums_freq.keys():
                nums_freq[i] += 1
            else:
                nums_freq[i] = 1
        max_freq = max(nums_freq.values())
        # if max_freq == 1:
        #     return 1
        keys = []
        for i in nums_freq.keys():
            if nums_freq[i] == max_freq:
                keys.append(i)
        # print(keys)
        
        start = {}
        end = {}
        for key in keys:
            pre = 0
            last = len(nums)
            flag1 = 0
            flag2 = 0
            while(pre < last):
                if nums[pre] == key and flag1 == 0:
                    start[key] = pre
                    flag1 = 1
                if nums[last-1] == key and flag2 == 0:
                    end[key] = last-1;
                    flag2 = 1
                if flag1 and flag2:
                    break
                if flag1 == 0:
                    pre += 1
                if flag2 == 0:
                    last -= 1
        # print(start)
        # print(end)
        cur = 60000
        for key in keys:
            if end[key] - start[key] < cur:
                cur = end[key] - start[key]
        return cur+1
        
                
        # print(keys)
            
        
        
        

