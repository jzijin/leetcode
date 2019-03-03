/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (35.62%)
 * Total Accepted:    35.2K
 * Total Submissions: 98.3K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 说明:
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 要求使用空间复杂度为 O(1) 的原地算法。
 * 
 * 
 */

// import java.util.Arrays;

// class Solution {
//     /**
//      * 双重循环
//      * 时间复杂度：O(kn)
//      * 空间复杂度：O(1)
//      */
//     public void rotate_1(int[] nums, int k) {
//         int n = nums.length;
//         k %= n;
//         for (int i = 0; i < k; i++) {
//             int temp = nums[n - 1];
//             for (int j = n - 1; j > 0; j--) {
//                 nums[j] = nums[j - 1];
//             }
//             nums[0] = temp;
//         }
//     }

//     /**
//      * 翻转
//      * 时间复杂度：O(n)
//      * 空间复杂度：O(1)
//      */
//     public void rotate_2(int[] nums, int k) {
//         int n = nums.length;
//         k %= n;
//         reverse(nums, 0, n - 1);
//         reverse(nums, 0, k - 1);
//         reverse(nums, k, n - 1);
//     }


//     private void reverse(int[] nums, int start, int end) {
//         while (start < end) {
//             int temp = nums[start];
//             nums[start++] = nums[end];
//             nums[end--] = temp;
//         }
//     }

//     /**
//      * 循环交换
//      * 时间复杂度：O(n^2/k)
//      * 空间复杂度：O(1)
//      */
//     public void rotate_3(int[] nums, int k) {
//         int n = nums.length;
//         k %= n;
//         // 第一次交换完毕后，前 k 位数字位置正确，后 n-k 位数字中最后 k 位数字顺序错误，继续交换
//         for (int start = 0; start < nums.length && k != 0; n -= k, start += k, k %= n) {
//             for (int i = 0; i < k; i++) {
//                 swap(nums, start + i, nums.length - k + i);
//             }
//         }
//     }

//     /**
//      * 递归交换
//      * 时间复杂度：O(n^2/k)
//      * 空间复杂度：O(1)
//      */
//     public void rotate(int[] nums, int k) {
//         // 原理同上
//         recursiveSwap(nums, k, 0, nums.length);
//     }

//     private void recursiveSwap(int[] nums, int k, int start, int length) {
//         k %= length;
//         if (k != 0) {
//             for (int i = 0; i < k; i++) {
//                 swap(nums, start + i, nums.length - k + i);
//             }
//             recursiveSwap(nums, k, start + k, length - k);
//         }
//     }

//     private void swap(int[] nums, int i, int j) {
//         int temp = nums[i];
//         nums[i] = nums[j];
//         nums[j] = temp;
//     }
// }

void rotate(int* nums, int numsSize, int k) {
    int * target = (int *)malloc(sizeof(int)*numsSize);
    for(int i=0; i< numsSize; i++)
    {
        int tmp = (i + k) % numsSize;
        target[tmp] = nums[i];
    }
    return target;
}
