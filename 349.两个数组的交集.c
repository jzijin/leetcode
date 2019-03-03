/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (59.38%)
 * Total Accepted:    13.2K
 * Total Submissions: 22.2K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int j=0;
    for(int i=0; i<nums1Size; i++)
    {
        for(int k=0; k<nums2Size; k++)
        {
            if(nums1[i] == nums2[k])
            {
                nums1[j++] = nums1[i];
                break;
            }
        }
    }
    
    
    // 先排序 在去重
    // 冒泡排序
    for(int i=0; i<j; i++)
    {
        for(int k=0; k<j-i-1; k++)
        {
            if(nums1[k] > nums1[k+1])
            {
                int tmp = nums1[k];
                nums1[k] = nums1[k+1];
                nums1[k+1] = tmp;
            }
        }
    }
    
    // 去重    
    for(int i=0; i<j-1; i++)
    {
        if(nums1[i] == nums1[i+1])
        {
            for(int k=i; k<j-1;k++)
            {
                nums1[k] = nums1[k+1];
            }
            j--;
            i--;
        }
    }
    
    
    int *target = (int *)malloc(sizeof(int)*(j));
    *returnSize = j;
    for(int i=0; i<j; i++)
    {
        target[i] = nums1[i];
    }
    return target;
}

