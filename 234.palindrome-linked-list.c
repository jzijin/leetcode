/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (34.82%)
 * Total Accepted:    15.4K
 * Total Submissions: 44.1K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
bool isPalindrome(struct ListNode *head)
{
    if (head == NULL)
    {
        return true;
    }
    struct ListNode *new_head = head;
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = head->val;
    p->next = NULL;
    head = head->next;
    while (head != NULL)
    {
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = head->val;
        q->next = p;
        p = q;
        head = head->next;
    }

    while (1)
    {
        if (p->val != new_head->val)
        {
            return false;
        }
        if (p->next == NULL)
        {
            break;
        }
        p = p->next;
        new_head = new_head->next;
    }

    return true;
}
*/



// 利用快慢指针 来快速找到 链表的中间节点
bool isPalindrome(struct ListNode *head)
{
    if (head == NULL)
    {
        return true;
    }

    // 快慢指针找到中间节点
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    // 注意判断条件 这个while 循环结束后 就得到链表的中间节点
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 翻转
    struct ListNode *prev = NULL;
    while (slow)
    {
        struct ListNode *ovn = slow->next;
        slow->next = prev;
        prev = slow;
        slow = ovn;
    }
    struct ListNode *a = head;
    struct ListNode *b = prev;
    while (a && b)
    {
        if (a->val != b->val)
        {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}
