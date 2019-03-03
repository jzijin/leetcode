/*
 * @lc app=leetcode.cn id=404 lang=c
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (48.33%)
 * Total Accepted:    4.4K
 * Total Submissions: 9.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// TODO: 值得进一步的优化
bool hasLeaf(struct TreeNode* root)
{
    
    if(root->left!=NULL || root->right!=NULL)
    {
        return true;
    }
    return false;
}
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL || (root->left==NULL&&root->right==NULL ))
    {
        return 0;
    }
    if(root->left==NULL&&root->right!=NULL)
    {
        if(hasLeaf(root->right))
        {
            return sumOfLeftLeaves(root->right);
        }
        return 0;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        if(hasLeaf(root->left))
        {
            return sumOfLeftLeaves(root->left);
        }
        return root->left->val;
    }
    if(hasLeaf(root->left) && hasLeaf(root->right))
    {
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    } 
    if(!hasLeaf(root->left) && !hasLeaf(root->right))
    {
        return root->left->val;
    } 
    if(hasLeaf(root->left) && !hasLeaf(root->right))
    {
        return sumOfLeftLeaves(root->left);
    }
    return root->left->val + sumOfLeftLeaves(root->right);
    
    
}