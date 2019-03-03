/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (38.67%)
 * Total Accepted:    15.7K
 * Total Submissions: 40.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *from_head = (struct ListNode *)malloc(sizeof(struct ListNode));
    from_head->next = head;
    struct ListNode *fast = head;
    struct ListNode *slow = from_head;

    while (1)
    {
        if (fast == NULL)
        {
            break;
        }
        if (slow->next->val == val)
        {
            slow->next = fast->next;
            fast = fast->next;
        }
        else
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    //printf("%d\n", from_head->next->val);
    return from_head->next;
}
