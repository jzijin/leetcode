/*
 * @lc app=leetcode.cn id=724 lang=c
 *
 * [724] 寻找数组的中心索引
 *
 * https://leetcode-cn.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (33.60%)
 * Total Accepted:    6.9K
 * Total Submissions: 20.5K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * 给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
 * 
 * 我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
 * 
 * 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * nums = [1, 7, 3, 6, 5, 6]
 * 输出: 3
 * 解释: 
 * 索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
 * 同时, 3 也是第一个符合要求的中心索引。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * nums = [1, 2, 3]
 * 输出: -1
 * 解释: 
 * 数组中不存在满足此条件的中心索引。
 * 
 * 说明:
 * 
 * 
 * nums 的长度范围为 [0, 10000]。
 * 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。
 * 
 * 
 */

int pivotIndex(int* nums, int numsSize) {
    if(numsSize == 0)
    {
        return -1;
    }
    if(numsSize == 1)
    {
        return nums[0];
    }
    int sum = 0;
    for (int =0;i<numsSize; i++)
    {
        sum += nums[i];
    }
    int left = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(2*left + nums[i] == sum)
        {
            return i;
        }
        left += nums[i];
    }
    return -1;
    // return 1;
    
}



/*
int getsum(int *nums, int start, int end)
{
    int sum = 0;
    
    for(int i=start; i<=end; i++)
    {
        sum += nums[i];
    }
    return sum;
}
int pivotIndex(int* nums, int numsSize) {
    if(numsSize == 0)
    {
        return -1;
    }
    if(numsSize == 1)
    {
        return nums[0];
    }
    int start = 0;
    int end = numsSize -1;
    int middle = 0;
    // printf("%d", getsum(nums, start, end));
    if (0 == getsum(nums, 1, end))
    {
        return 0;
    }
    for(int i= 1; i<numsSize-1;i++)
    {
        // printf("left = %d right = %d", getsum(nums, start, i-1),getsum(nums, i+1, end));
        if(getsum(nums, start, i-1) == getsum(nums, i+1, end))
        {
            return i;
        }
    }
    if (0 == getsum(nums, 0, end-1))
    {
        return end;
    }
    return -1;
    // return 1;
    
}
*/
