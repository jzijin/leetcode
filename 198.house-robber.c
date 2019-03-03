/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (38.89%)
 * Total Accepted:    15.7K
 * Total Submissions: 40.2K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */
/*
int rob(int* nums, int numsSize) {
    if(numsSize == 2)
    {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    if(numsSize == 1)
    {
        return nums[0];
    }
    
    int max_num = nums[0];
    for(int i=0; i<numsSize; i++)
    {
        int sum = 0;
        sum += nums[i];
        int * tmp = (int *)malloc(sizeof(int)*(numsSize-i-2));
        for (int j = 0; j < numsSize - i - 2; j++)
        {
            tmp[j] = nums[j+i+2];
        }
        sum += rob(tmp, numsSize - i - 2);
        if(sum > max_num)
        {
            max_num = sum;
        }
    }
    return max_num;
}
*/
int rob(int *nums, int numsSize)
{
    int maxVal = 0, prevVal = 0, currVal = 0;
    if (numsSize == 0)
    {
        maxVal = 0;
    }
    else if (numsSize == 1)
    {
        maxVal = nums[0];
    }
    else
    {
        maxVal = nums[0];  // 存储最大值
        prevVal = nums[1]; // 存储预期值？
        for (int i = 2; i < numsSize; i++)
        {
            currVal = nums[i] + maxVal;                   //Calculating Max Value except PrevElement,as Adjacent elements should be skipped
            maxVal = maxVal < prevVal ? prevVal : maxVal; //Updating MaxVal by comparing with PrevElement
            prevVal = currVal;
        }
    }
    return maxVal < prevVal ? prevVal : maxVal;
}
