/*
 * @lc app=leetcode.cn id=107 lang=c
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (58.29%)
 * Total Accepted:    9.4K
 * Total Submissions: 16K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 后序遍历
/*
void PostOrder(TreeNode *root)
{
    if (root == NULL)
    {
        printf("# ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}
--------------------- 
作者：Monster_ii 
来源：CSDN 
原文：https://blog.csdn.net/monster_ii/article/details/82115772 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
// 中序遍历
/*
void InOrder(const TreeNode *root)
{
    if (root == NULL)              //判断节点是否为空
    {
        printf("# ");
        return;
    }
    InOrder(root->left);           //中序遍历左子树
    printf("%c ", root->data);     //访问节点值
    InOrder(root->right);          //中序遍历右子树
}
--------------------- 
作者：Monster_ii 
来源：CSDN 
原文：https://blog.csdn.net/monster_ii/article/details/82115772 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
/*前序遍历
void PreOrder(const TreeNode *root)
{
    if (root == NULL)                 //若结点为空
    {
        printf("# ");
        return;
    }
    printf("%c ", root->data);        //输出根节点的值
    PreOrder(root->left);             //前序访问左子树
    PreOrder(root->right);            //前序访问右子树
}
--------------------- 
作者：Monster_ii 
来源：CSDN 
原文：https://blog.csdn.net/monster_ii/article/details/82115772 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/ 
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    
}
