/*
 * @lc app=leetcode.cn id=665 lang=c
 *
 * [665] 非递减数列
 *
 * https://leetcode-cn.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Easy (18.53%)
 * Total Accepted:    3.9K
 * Total Submissions: 20.8K
 * Testcase Example:  '[4,2,3]'
 *
 * 给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 * 
 * 我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [4,2,3]
 * 输出: True
 * 解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [4,2,1]
 * 输出: False
 * 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 * 
 * 
 * 说明:  n 的范围为 [1, 10,000]。
 * 
 */

 // 思路如下：
    // 如果出现 a[i] > a[i+1]   改变一个数 就面临两种选择
    // 1. 把a[i]变大
    // 2. 把a[i+1] 变小
    // 这两种选择其实是有依据的 需要比较a[i-1] 与 a[i+1]的值
    // eg.  ... 1 4 3 ...   只能选择把4变小   ... 3 4 1 ... 只能选择把1变大
    // 改变完之后，记录改变次数，再检测是否升序
    // 如果次数大于1，至少改了两次 返回false
    
    // 先让前两个有序
    // 因为没有左边没有数 所以对于前两个数来说，最佳选择就是吧 a[0] 变小
bool checkPossibility(int* nums, int numsSize) {
    if(numsSize < 3)
    {
        return true;
    }
    int changecount = 0;
    if(nums[0] > nums[1])
    {
        nums[0] = nums[1];
        changecount++;
    }
    for (int i=1; i<numsSize-1;i++)
    {
        int right = nums[i+1];
        if(nums[i] > right)
        {
            changecount++;
            if(changecount > 1)
            {
                return false;
            }
            int left = nums[i-1];
            if(left > right)
            {
                nums[i+1] = nums[i];
            }
            else
            {
                nums[i] = left;
            }
        }
    }
    return true;
}

