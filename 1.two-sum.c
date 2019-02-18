/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.16%)
 * Total Accepted:    231.5K
 * Total Submissions: 524.3K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j, sum = -1, io, jo, flag = 0;
  for (i = 0; i < numsSize; i++)
  {
    for (j = 0; j < numsSize; j++)
    {
      if (i != j)
      {
        sum = nums[i] + nums[j];
        if (sum == target)
        {
          io = i;
          jo = j;
          flag = 1;
          break;
        }
      }
    } 
    if (flag)
      break;
  }
  int *out = malloc(sizeof(int) * 2);
  out[0] = io < jo ? io : jo;
  out[1] = io > jo ? io : jo;
  return out;
}
