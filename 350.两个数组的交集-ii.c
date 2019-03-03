/*
 * @lc app=leetcode.cn id=350 lang=c
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (38.61%)
 * Total Accepted:    23.8K
 * Total Submissions: 61.6K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [4,9]
 * 
 * 说明：
 * 
 * 
 * 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 * 进阶:
 * 
 * 
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{

    if (nums1Size < nums2Size)
    {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;

        int num = nums1Size;
        nums1Size = nums2Size;
        nums2Size = num;
    }
    int index = 0;
    // 定义flag 数组来标识是否已经匹配过的字符 匹配数组选择小的 节省空间开销
    int *flag = (int *)malloc(sizeof(int) * nums2Size);
    memset(flag, 0, nums2Size);
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            // 如果已经匹配过的话 结束本次
            if (flag[j] == 1)
            {
                continue;
            }
            if (nums1[i] == nums2[j])
            {
                // 匹配到的话 设定匹配数组
                flag[j] = 1;
                // 设定值
                nums1[index++] = nums1[i];
                break;
            }
        }
    }
    *returnSize = index;
    int *target = (int *)malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++)
    {
        target[i] = nums1[i];
    }
    return target;
}
