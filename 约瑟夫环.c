#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode * next;
};

struct ListNode * create(int n)
{
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = head;
    head->val = 1;
    head->next = NULL;
    int i = 2;
    while(i<=n){
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = i;
        p->next = NULL;
        q->next = p;
        q = p;
        i++;
    }

    q->next = head;
    return head;
    
}

int main()
{
    struct ListNode * head = create(2);
    struct ListNode * p = head;
    struct ListNode * q = head;
    // while(p->next!=head)
    // {
    //     printf("%d ", p->val);
    //     p = p->next;
    // }
    // printf("%d ", p->val);
    int i=1;
    while(1)
    {
        
        if(i%3==0)
        {
            if(p->next == q)
            {
                q->next = NULL;
                break;
            }
            q->next = p->next;
            i=1;
        }
        else
        {
            i++;
        }
        q = p;
        p = p->next;        
        
    }
    
    // q就是最后剩下的
    printf("%d ", q->val);
    // printf("%d ", p->val);

    return 0;
}
