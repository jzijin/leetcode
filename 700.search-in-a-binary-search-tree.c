/*
 * @lc app=leetcode.cn id=700 lang=c
 *
 * [700] Search in a Binary Search Tree
 *
 * https://leetcode-cn.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (63.38%)
 * Total Accepted:    4.2K
 * Total Submissions: 6.5K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
 * 
 * 例如，
 * 
 * 
 * 给定二叉搜索树:
 * 
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * 
 * 和值: 2
 * 
 * 
 * 你应该返回如下子树:
 * 
 * 
 * ⁠     2     
 * ⁠    / \   
 * ⁠   1   3
 * 
 * 
 * 在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。
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
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // return root->right;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->val == val)
    {
        return root;
    }else if(val > root->val) // 如果要搜索的值大于当前值 在右子树搜索
    {
        return searchBST(root->right, val);
    }
    else // 如果要搜索的值小于当前值 在左子树搜索
    {
        return searchBST(root->left, val);
    }
    
    
}
