/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (56.20%)
 * Total Accepted:    19K
 * Total Submissions: 33.5K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
int majorityElement(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    int count = 1;
    int num = nums[0];

    // 主要是会抵消 众数大于一半 要学会相同加1 不同抵消的思想来转换！！！
    for (int i = 1; i < numsSize; i++)
    {
        if (num == nums[i])
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                num = nums[i + 1];
            }
        }
    }
    return num;
}
