/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.15%)
 * Total Accepted:    79.2K
 * Total Submissions: 246.5K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode)), *tail = head; //空的头结点
    int carry = 0;                                                                            //进位
    for (; l1 && l2; l1 = l1->next, l2 = l2->next)
    {                                        //处理两条链公共长度部分
        int sum = l1->val + l2->val + carry; //计算当前和
        if (sum > 9)
        { //处理进位
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        //分配结点
        tail->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = sum;
    }
    //取两条链长的那条剩下的部分
    l1 = l1 ? l1 : l2;
    //遍历剩余部分
    for (; l1; l1 = l1->next)
    {
        //加上进位计算结点值
        int sum = l1->val + carry;
        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        //分配结点
        tail->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = sum;
    }
    //如果最后还有进位，再分配一个结点
    if (carry)
    {
        tail->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = 1; //加法的进位只可能是1
    }
    tail->next = NULL; //将链表收尾
    //将空的头结点释放，从第二个结点返回
    tail = head;
    head = head->next;
    free(tail);
    return head;
}
