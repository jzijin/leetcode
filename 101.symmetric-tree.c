/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.59%)
 * Total Accepted:    20.7K
 * Total Submissions: 46.3K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
bool isMirror(struct TreeNode *left_tree, struct TreeNode *right_tree)
{
    if (left_tree == NULL && right_tree == NULL)
    {
        return true;
    }
    if (left_tree == NULL || right_tree == NULL)
    {
        return false;
    }
    return (left_tree->val == right_tree->val) && isMirror(left_tree->right, right_tree->left) && isMirror(left_tree->left, right_tree->right);
}
bool isSymmetric(struct TreeNode *root)
{
    return isMirror(root, root);
}
