/*
 * @lc app=leetcode.cn id=136 lang=c
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (57.04%)
 * Total Accepted:    38.7K
 * Total Submissions: 67.5K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */
// 并不是普遍使用
/*
int singleNumber(int *nums, int numsSize)
{
    int index = 0;     //记录index
    int num = nums[0]; //记录num
    for (int i = 1; i < numsSize; i++)
    {
        if (i == index)
        {
            continue;
        }
        if (nums[i] == num)
        {
            nums[i] = 0;
            nums[index] = 0;
            while (1)
            {
                index++;
                if (nums[index] != 0)
                {
                    num = nums[index];
                    i = index;
                    break;
                }
            }
        }
    }
    return nums[index];
}
*/
int singleNumber(int *nums, int numsSize)
{
    // 异或一个数两次 这个数不变。
    // 用初始的0 去异或。神奇。
    int target = 0;
    for (int i = 0; i < numsSize; i++)
    {
        target ^= nums[i];
    }
    return target;
}
