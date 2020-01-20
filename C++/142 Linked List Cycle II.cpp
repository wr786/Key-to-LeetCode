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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL; // no cycle
        if(head->val == INT_MAX) {return head;}
        else {
            head->val = INT_MAX; // vis
            return detectCycle(head->next);
        }
    }
};