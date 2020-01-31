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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* child = head->next;
        while(child != NULL) {
            if(child->val == head->val) child = child->next;
            else {
                child = deleteDuplicates(child);
                break;
            }
        }
        head->next = child;
        return head;
    }
};