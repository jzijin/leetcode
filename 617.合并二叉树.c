/*
 * @lc app=leetcode.cn id=617 lang=c
 *
 * [617] 合并二叉树
 *
 * https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (66.91%)
 * Total Accepted:    6.9K
 * Total Submissions: 10.3K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 * 
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL
 * 的节点将直接作为新二叉树的节点。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * 输出: 
 * 合并后的树:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 注意: 合并必须从两个树的根节点开始。
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

// class Solution(object):
//     def mergeTrees(self, t1, t2):
//         """
//         :type t1: TreeNode
//         :type t2: TreeNode
//         :rtype: TreeNode
//         """
//         if t1 is None:
//             return t2
//         if t2 is None:
//             return t1
        
//         # 先合并根节点
//         t1.val += t2.val;
//         # 递归合并左子树和右子树
//         t1.left = self.mergeTrees(t1.left, t2.left)
//         t1.right = self.mergeTrees(t1.right, t2.right)
//         return t1
        
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(!t1)
        return t2;
    if(!t2)
        return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

