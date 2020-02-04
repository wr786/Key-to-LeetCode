/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val) head = head->next;
        if(head == NULL) return head;
        ListNode* cur = head->next;
        ListNode* last = head;
        while(cur != NULL) {
            while(cur != NULL && cur->val == val) cur = cur->next;
            last->next = cur;
            last = cur;
            if(cur != NULL) cur = cur->next;
        }
        return head;
    }
};