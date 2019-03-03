/*
 * @lc app=leetcode.cn id=414 lang=c
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (30.61%)
 * Total Accepted:    5.5K
 * Total Submissions: 17.9K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */
int thirdMax(int *nums, int numsSize)
{
    // 只需要跑一遍for循环就可以了 还行！
    int min_num = nums[0];
    int mid_num = nums[0];
    int max_num = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > max_num)
        {
            if (mid_num == max_num)
            {
                max_num = nums[i];
            }
            else
            {
                min_num = mid_num;
                mid_num = max_num;
                max_num = nums[i];
            }
        }
        if (nums[i] < min_num)
        {
            if (max_num == mid_num && max_num == min_num || mid_num == min_num)
            {
                min_num = nums[i];
            }
            else if (max_num == mid_num)
            {
                mid_num = min_num;
                min_num = nums[i];
            }
        }
        if (nums[i] < max_num && nums[i] > min_num)
        {
            if (nums[i] > mid_num)
            {
                if (max_num == mid_num)
                {
                    max_num = nums[i];
                }
                else
                {
                    min_num = mid_num;
                    mid_num = nums[i];
                }
            }
            else if (nums[i] < mid_num)
            {
                if (max_num == mid_num)
                {
                    mid_num = nums[i];
                }
                else
                {
                    min_num = nums[i];
                }
            }
        }
    }
    printf("max=%d\nmin=%d\nmid=%d\n", max_num, min_num, mid_num);
    if (max_num == mid_num || min_num == mid_num || max_num == min_num)
    {
        return max_num;
    }
    return min_num;
}
