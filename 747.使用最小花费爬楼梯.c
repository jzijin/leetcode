/*
 * @lc app=leetcode.cn id=747 lang=c
 *
 * [747] 使用最小花费爬楼梯
 *
 * https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (38.46%)
 * Total Accepted:    6.1K
 * Total Submissions: 16K
 * Testcase Example:  '[0,0,0,1]'
 *
 * 在一个给定的数组nums中，总是存在一个最大元素 。
 * 
 * 查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
 * 
 * 如果是，则返回最大元素的索引，否则返回-1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [3, 6, 1, 0]
 * 输出: 1
 * 解释: 6是最大的整数, 对于数组中的其他整数,
 * 6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1, 2, 3, 4]
 * 输出: -1
 * 解释: 4没有超过3的两倍大, 所以我们返回 -1.
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * nums 的长度范围在[1, 50].
 * 每个 nums[i] 的整数范围在 [0, 99].
 * 
 * 
 */
// TODO: 这题和打家劫舍很像 想想什么是动态规划
/*终于想明白了
长度为n的数组 cost[n], 下标从1开始
f(n) = min(f(n-1), f(n-2)) + cost[n]   走到n阶的方法只有两种，从 n-1 或 n-2 上去，这时你是站到了n阶上 所以花费要 +cost[n]
但最终结果是要站到楼上，不是最后一阶上
所以最终结果是，min(f(n), f(n-1))
？？？？
*/
int minCostClimbingStairs(int* cost, int costSize) {
    int minVal=0;
    int preVal=0;
    int allcost=0;
    for(int i=0; i<costSize-1; i++)
    {
        if(cost[i]+minVal > cost[i+1]+preVal)
        {
            allcost = cost[i+1] + preVal;
        }
        else
        {
            allcost = cost[i] + minVal;
        }
        minVal = preVal;
        preVal = allcost;
        
    }
    // printf("minVal = %d preVal = %d", minVal, preVal);
    return allcost;
}

