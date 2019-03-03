/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (52.38%)
 * Total Accepted:    33.3K
 * Total Submissions: 63.6K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */
void moveZeroes(int *nums, int numsSize)
{
    // 自己写的方法一
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (!nums[i])
        {
            for (int j = i; j < numsSize - 1; j++)
            {
                nums[j] = nums[j + 1];
            }
            nums[numsSize - 1] = 0;
            numsSize--;
            i--;
        }
    }
    // 参考的方法二
    // int j=0;
    // for(int i=0; i<numsSize; i++)
    // {
    //     if(nums[i] != 0)
    //     {
    //         nums[j++] = nums[i];
    //     }       
    // }
    // while(j < numsSize)
    // {
    //     nums[j++] = 0;
    // }
}
