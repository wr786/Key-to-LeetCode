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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* cur = ret;
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 != nullptr) {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                cur->val += l2->val;
                l2 = l2->next;
            }
            int upDigit = cur->val / 10;
            cur->val %= 10;
            if(l1 != nullptr || l2 != nullptr || upDigit)
                cur->next = new ListNode(upDigit),
                cur = cur->next;
        }
        return ret;
    }
};