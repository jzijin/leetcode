//https://www.cnblogs.com/TenosDoIt/p/3666585.html
// 单链表的快速排序
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