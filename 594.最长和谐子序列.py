#
# @lc app=leetcode.cn id=594 lang=python
#
# [594] 最长和谐子序列
#
# https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
#
# algorithms
# Easy (38.56%)
# Total Accepted:    2.1K
# Total Submissions: 5.3K
# Testcase Example:  '[1,3,2,2,5,2,3,7]'
#
# 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
# 
# 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
# 
# 示例 1:
# 
# 
# 输入: [1,3,2,2,5,2,3,7]
# 输出: 5
# 原因: 最长的和谐数组是：[3,2,2,2,3].
# 
# 
# 说明: 输入的数组长度最大不超过20,000.
# 
#
class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        nums.sort()
        nums_freq = {}
        for i in nums:
            if i in nums_freq.keys():
                nums_freq[i] += 1;
            else:
                nums_freq[i] = 1
        target = 0
        for i in range(0, len(nums)-1):
            if nums[i+1] - nums[i] == 1:
                tmp = nums_freq[nums[i]] + nums_freq[nums[i+1]]
                if target < tmp:
                    target = tmp
        return target
        
    
        # print(aaa)
        
        
        
        # return max(target)
            
            
        
        

