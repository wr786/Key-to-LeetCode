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
    map<ListNode*, bool> vis;

    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL; // no cycle
        if(vis[head]) {return head;}
        else {
            vis[head] = true;
            return detectCycle(head->next);
        }
    }
};