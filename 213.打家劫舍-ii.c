/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (31.98%)
 * Total Accepted:    3.8K
 * Total Submissions: 11.8K
 * Testcase Example:  '[2,3,2]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,2]
 * 输出: 3
 * 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 */
// 做两次打家劫舍1 就行了嘛 你麻痹的 这么笨
int max(int a, int b)
{
    return a>b ? a:b;
}
int rob(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return max(nums[0], nums[1]);
    
    // 做两次打家劫舍
    int *dp1 = (int *)malloc(sizeof(int)*(numsSize-1));
    int *dp2 = (int *)malloc(sizeof(int)*(numsSize-1));
    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);
    // 不考虑最后一家
    for(int i=2; i<numsSize-1; i++)
    {
        dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
    }
    
    // 不考虑第一家
    dp2[0] = nums[1];
    dp2[1] = max(nums[1], nums[2]);
    // 注意边界条件
    for(int i=3; i<numsSize; i++)
    {
        dp2[i-1] = max(dp2[i-1-1], dp2[i-1-2]+nums[i]);
    }
    
    return max(dp1[numsSize-2], dp2[numsSize-2]);
    
}

