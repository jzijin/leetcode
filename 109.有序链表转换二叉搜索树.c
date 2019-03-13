/*
 * @lc app=leetcode.cn id=109 lang=c
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (62.32%)
 * Total Accepted:    4K
 * Total Submissions: 6.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
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
// 快慢指针寻找中间结点 然后递归创建就可以了。
struct TreeNode *build(struct ListNode *start, struct ListNode *end)
{
    if (start == end || start == NULL)
    {
        return NULL;
    }
    struct ListNode *oneStep = start;
    struct ListNode *twoStep = start;
    while (twoStep != end && twoStep->next != end)
    {
        oneStep = oneStep->next;
        twoStep = twoStep->next->next;
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = oneStep->val;
    root->left = build(start, oneStep);
    root->right = build(oneStep->next, end);
    // exit(0);
    return root;
}
struct TreeNode *sortedListToBST(struct ListNode *head)
{
    if (!head)
    {
        return NULL;
    }
    return build(head, NULL);
}
