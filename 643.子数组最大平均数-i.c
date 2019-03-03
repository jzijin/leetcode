/*
 * @lc app=leetcode.cn id=643 lang=c
 *
 * [643] 子数组最大平均数 I
 *
 * https://leetcode-cn.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (32.73%)
 * Total Accepted:    3.3K
 * Total Submissions: 10.2K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
 * 
 * 示例 1:
 * 
 * 输入: [1,12,-5,-6,50,3], k = 4
 * 输出: 12.75
 * 解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 1 <= k <= n <= 30,000。
 * 所给数据范围 [-10,000，10,000]。
 * 
 * 
 */
double findMaxAverage(int* nums, int numsSize, int k) {
    // 滑动窗口的问题
    double m;
    long sum = 0,temp;
    for(int i = 0;i < k;i++)
        sum = sum + nums[i];
    temp = sum;
    for(int i = k;i < numsSize;i++)
    {
        temp = temp - nums[i-k] + nums[i];
        if(sum < temp)
            sum = temp;
    }
    m = (double) sum / k;
    return m;
}

