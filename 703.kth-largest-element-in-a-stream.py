#
# @lc app=leetcode.cn id=703 lang=python
#
# [703] Kth Largest Element in a Stream
#
# https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/description/
#
# algorithms
# Easy (34.86%)
# Total Accepted:    2.6K
# Total Submissions: 7.4K
# Testcase Example:  '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
#
# 设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
# 
# 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用
# KthLargest.add，返回当前数据流中第K大的元素。
# 
# 示例:
# 
# 
# int k = 3;
# int[] arr = [4,5,8,2];
# KthLargest kthLargest = new KthLargest(3, arr);
# kthLargest.add(3);   // returns 4
# kthLargest.add(5);   // returns 5
# kthLargest.add(10);  // returns 5
# kthLargest.add(9);   // returns 8
# kthLargest.add(4);   // returns 8
# 
# 
# 说明: 
# 你可以假设 nums 的长度≥ k-1 且k ≥ 1。
# 
#
# 排序算法如何选择才能使得时间的使用 比较少呢？？？？？？
class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.k = k
        # i=0
        # while i<len(nums)-1:
        #     j = 0
        #     while j<len(nums)-1-i:
        #         if nums[j] < nums[j+1]:
        #             tmp = nums[j]
        #             nums[j] = nums[j+1]
        #             nums[j+1] = tmp
        #         j += 1
        #     i += 1
        # print(nums)
        self.nums = sorted(nums, reverse=True)[:k]
        # print(self.nums)
        

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        self.nums.append(val)
        # i=0
        # while i<len(self.nums)-1:
        #     k = i
        #     j = k+1
        #     while j<len(self.nums):
        #         if self.nums[j] > self.nums[k]:
        #             k = j
        #         j += 1
        #     if i!= k:
        #         tmp = self.nums[i]
        #         self.nums[i] = self.nums[k]
        #         self.nums[k] = tmp
        #     i += 1
        # print(self.nums)
        self.nums = sorted(self.nums, reverse=True)[:self.k]
        return self.nums[-1]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)

