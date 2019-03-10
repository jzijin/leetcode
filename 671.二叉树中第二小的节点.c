/*
 * @lc app=leetcode.cn id=671 lang=c
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (45.48%)
 * Total Accepted:    2K
 * Total Submissions: 4.5K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * 输出: 5
 * 说明: 最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * 输出: -1
 * 说明: 最小的值是 2, 但是不存在第二小的值。
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

// 根节点就是最小的不用找所有的树 只要发现有比较根节点大的直接返回就行了
int findnum(struct TreeNode* root, int val)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->val > val)
    {
        return root->val;
    }
    
        int left = findnum(root->left, val);        
        int right = findnum(root->right, val);
        // return left > right ? right: left;
    if(left == -1)
    {
        return right;
    }
    if (right == -1)
    {
        return left;
    }
    return left > right ? right: left;

    
}
int findSecondMinimumValue(struct TreeNode* root) {
    return findnum(root, root->val);    
}
