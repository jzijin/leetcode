/*
 * @lc app=leetcode.cn id=687 lang=c
 *
 * [687] 最长同值路径
 *
 * https://leetcode-cn.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (32.94%)
 * Total Accepted:    2.3K
 * Total Submissions: 7K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
 * 
 * 注意：两个节点之间的路径长度由它们之间的边数表示。
 * 
 * 示例 1:
 * 
 * 输入:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
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
int global_max = 0;
int finglong(struct TreeNode* root, int val)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = finglong(root->left, root->val); // 找左子树 注意要改变val 才能遍历完整棵树
    int right = finglong(root->right,  root->val);// 找右子树
    global_max = left+right > global_max ? left+right : global_max;// 设置global_max
    if(root->val == val)// 如果相等的话应该返回 
    {
        return left > right? left+1 : right+1;
    }
    return 0;
}
int longestUnivaluePath(struct TreeNode* root) {
    global_max = 0;
    if(root == NULL)
    {
        return 0;
    }
    finglong(root,root->val);
    return global_max;
}

