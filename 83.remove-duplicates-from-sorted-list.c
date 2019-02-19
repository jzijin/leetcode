/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.30%)
 * Total Accepted:    15.7K
 * Total Submissions: 36.3K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
    {
        return head;
    }
    struct ListNode *ptr = head;
    // 注意这边要是 ptr->next 不然if判断不成立
    while (ptr->next != NULL)
    {
        if (ptr->val == ptr->next->val)
        {
            ptr->next = ptr->next->next;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return head;
}
