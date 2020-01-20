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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false; // bug-free
        if(head->next == NULL) return false;
        if(head->val == INT_MAX) return true;
        else {
            head->val = INT_MAX;
            return hasCycle(head->next);
        }
    }
};