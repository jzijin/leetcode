/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (57.39%)
 * Total Accepted:    33.9K
 * Total Submissions: 58.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
    // 如果只有一个元素 直接返回
    // if( head == NULL || head->next == NULL)
    // {
    //     return head;
    // }
    // struct ListNode* p = head;
    // // 找到倒数第二个 元素 返回最后一个元素 然后截断最后一个元素
    // while(p->next->next != NULL)
    // {
    //     p = p->next;
    // }
    // struct ListNode* q = p->next;
    // p->next = NULL;
    // q->next = reverseList(head);
    // return q;

    /*var reverseList = function(head) {
    //已经反转的节点引用
    var reversed = null
    //当前操作节点
    var currentNode = head
    //下一个节点
    var nextNode = null
    
    while (currentNode) {
        //保存当前节点的下一个节点
        nextNode = currentNode.next
        //下一个节点指向reversed
        currentNode.next = reversed
        //重置reversed
        reversed = currentNode
        //后移currentNode
        currentNode = nextNode
    }
    
    return reversed
};
*/

    // 直接翻转
    if(head == NULL)
    {
        return head;
    }
    struct ListNode *reversed = NULL;
    struct ListNode *currentNode = head;
    struct ListNode *nextNode = NULL;
    while(currentNode)
    {
        nextNode = currentNode->next;
        currentNode->next = reversed;
        reversed = currentNode;
        currentNode = nextNode;
    }
    return reversed;


    // 重新建立链表的做reversed法
    if (head == NULL)
    {
        return head;
    }
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
    return p;
}