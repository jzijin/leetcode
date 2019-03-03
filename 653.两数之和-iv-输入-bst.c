/*
 * @lc app=leetcode.cn id=653 lang=c
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (49.55%)
 * Total Accepted:    3.1K
 * Total Submissions: 6.2K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 案例 1:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * 输出: True
 * 
 * 
 * 
 * 
 * 案例 2:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * 输出: False
 * 
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
bool findVal(struct TreeNode* root, int val)
{
    if(root == NULL)
    {
        return false;
    }
    if(val == root->val)
    {
        return true;
    }
    if(val > root->val)
    {
        return findVal(root->right, val);
    }else if(val < root->val)
    {
        return findVal(root->left, val);
    }
    return false;
}
bool findaa(struct TreeNode *root, struct TreeNode *node, int k)
{
    if(node == NULL)
    {
        return false;
    }
    int tmp = k-node->val;
    if(tmp != node->val)
    {
        if(findVal(root, tmp))
    {
        return true;
    }
    }
    // if(findVal(root, tmp))
    // {
    //     return true;
    // }
    // struct TreeNode* left = root->left;
    return findaa(root, node->left, k) || findaa(root, node->right, k);
}

bool findTarget(struct TreeNode* root, int k) {
    if(root == NULL)
    {
        return false;
    }
    // printf("%d\n", findVal(root, 3));
    // exit(0);
    struct TreeNode* node = root;
   return findaa(root, node, k);
}

