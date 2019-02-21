/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (60.05%)
 * Total Accepted:    12.3K
 * Total Submissions: 20.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 排序完了的 可以直接用中间值来当root节点 递归就能实现 创建平衡二叉树
struct TreeNode *bulidTree(int *nums, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }
    int middle = (left + right) / 2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[middle];
    root->left = bulidTree(nums, left, middle - 1);
    root->right = bulidTree(nums, middle + 1, right);
    return root;
}
struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (numsSize == 0 || nums == NULL)
    {
        return NULL;
    }
    return bulidTree(nums, 0, numsSize - 1);
}