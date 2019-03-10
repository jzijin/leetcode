/*
 * @lc app=leetcode.cn id=704 lang=c
 *
 * [704] Binary Search
 *
 * https://leetcode-cn.com/problems/binary-search/description/
 *
 * algorithms
 * Easy (46.89%)
 * Total Accepted:    6.7K
 * Total Submissions: 14.3K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
 * target，如果目标值存在返回下标，否则返回 -1。
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 * 
 * 
 */
int search(int* nums, int numsSize, int target) {
    if(numsSize==1 && nums[0] != target)
    {
        return -1;
    }
    int start = 0;
    int end = numsSize-1; // 注意
    int middle;
    while(start <= end) // 注意
    {
        middle = (start+end)/2;
        if(nums[middle] == target)
        {
            return middle;
        }
        else if(nums[middle] > target)
        {
            end = middle-1; // 注意
        }
        else 
        {
            start = middle+1; // 注意
        }
    }
    return -1;
}

