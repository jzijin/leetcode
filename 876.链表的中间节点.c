/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// TODO: 主要用到了快慢指针的思想
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;    
    struct ListNode* slow = head;
    while(fast != NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}