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
        bool flag = false;
        while(child != NULL) {
            if(child->val == head->val) {
                child = child->next;
                flag = true;
            }
            else {
                child = deleteDuplicates(child);
                break;
            }
        }
        if(flag) return child;
        head->next = child;
        return head;
    }
};