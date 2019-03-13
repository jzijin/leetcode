/*
 * @lc app=leetcode.cn id=148 lang=c
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (58.16%)
 * Total Accepted:    8K
 * Total Submissions: 13.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void quicksort(struct ListNode* start, struct ListNode* end)
{
    
    if(start==end)
    {
        return;
    }
    struct ListNode* first = start;
    struct ListNode* second = start->next;
    int midValue = start->val; // 记录基准元素
    while(second != end && second != NULL)
    {
        if(second->val < midValue)
        {
            // printf("second-val = %d ", second->val);
            first = first->next;
            int temp = second->val;
            second->val = first->val;
            first->val = temp;
        }
        second = second->next; // 指向下一个结点
    }
    start->val = first->val;
    first->val = midValue;
    quicksort(start, first);
    quicksort(first->next, end);
    
}
struct ListNode* sortList(struct ListNode* head) {
    quicksort(head, NULL);
    return head;
}

