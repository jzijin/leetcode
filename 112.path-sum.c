/*
 * @lc app=leetcode.cn id=112 lang=c
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (44.20%)
 * Total Accepted:    10.6K
 * Total Submissions: 23.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
int getSum(struct TreeNode *root, int tmp, int sum)
{
    if (root == NULL)
    {
        return false;
    }
    tmp += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        return tmp == sum;
    }
    else
    {
        return getSum(root->left, tmp, sum) || getSum(root->right, tmp, sum);
    }
}
bool hasPathSum(struct TreeNode *root, int sum)
{
    return getSum(root, 0, sum);
}

/*bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL && root->val == sum)
        return true;
    return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
}*/