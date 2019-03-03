/*
 * @lc app=leetcode.cn id=219 lang=c
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (32.47%)
 * Total Accepted:    8.6K
 * Total Submissions: 26.3K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j
 * 的差的绝对值最大为 k。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 * 
 */
bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    if (numsSize <= 1)
    {
        return false;
    }
    int tmp;
    for (int i = 0; i < numsSize - 1; i++)
    {
        tmp = i + k;
        if (tmp >= numsSize - 1)
        {
            tmp = numsSize - 1;
        }
        printf("%d\n", tmp);
        for (int j = i + 1; j <= tmp; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}