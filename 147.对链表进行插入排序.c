/*
 * @lc app=leetcode.cn id=147 lang=c
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (55.14%)
 * Total Accepted:    4.5K
 * Total Submissions: 8.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 对链表进行插入排序。
 * 
 * 
 * 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 * 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 * 
 * 
 * 
 * 插入排序算法：
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2：
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
struct ListNode *insertionSortList(struct ListNode *head)
{

    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *p = head->next; // 存放每次待排序的元素
    struct ListNode *old = head;     // 存放上一次循环到的结点
    struct ListNode *now = head;     // 存放当前循环到的结点
    struct ListNode *tail = head;    // 存放最后一个元素
    struct ListNode *new_p = NULL;   // 存放下一个结点的临时变量

    // 第一个元素已经排好了
    while (p != NULL)
    {
        old = NULL;
        now = head;
        while (1)
        {

            if (now->val <= p->val)
            {
                old = now;
                now = now->next;
                if (now == p)
                {
                    new_p = p->next;
                    tail = p;
                    break;
                }
            }
            else
            {
                if (old == NULL)
                {

                    // 应该把结点插入到第一个元素
                    new_p = p->next;
                    tail->next = p->next;

                    p->next = head;
                    head = p; // 更新head头信息
                }
                else
                {
                    new_p = p->next;      // 记录下一个结点
                    tail->next = p->next; // 连接上尾结点

                    p->next = now;
                    old->next = p;
                }
                break;
            }
        }
        p = new_p;
    }

    return head;
}