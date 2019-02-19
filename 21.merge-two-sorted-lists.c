/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (51.98%)
 * Total Accepted:    41.2K
 * Total Submissions: 79.2K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *last = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *start = (struct ListNode *)malloc(sizeof(struct ListNode));
    start = last;
    start->next = NULL;
    while (l1!=NULL && l2!=NULL)
    {
        if (l1->val <= l2->val)
        {
            last->next = l1;
            last = last->next;
            l1 = l1->next;
        }
        else
        {
            last->next = l2;
            last = last->next;
            l2 = l2->next;
        }
    }
    if (l1 == NULL && l2 != NULL)
    {
        last->next = l2;
    }
    if (l2 == NULL && l1 != NULL)
    {
        last->next = l1;
    }
    return start->next;
}
