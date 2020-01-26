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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // 代码复用
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l2->val < l1->val) swap(l1, l2);
        ListNode* curl1 = l1;
        ListNode* lastl1 = l1;
        while(l2 != NULL) { // merge l2 into l1
            if(curl1 == NULL) {
                lastl1->next = l2;
                break;
            } else {
                if(curl1->val <= l2->val) {
                    lastl1 = curl1;
                    curl1 = curl1->next;
                } else {
                    lastl1->next = l2;
                    lastl1 = l2;
                    ListNode* tmp = l2->next;
                    l2->next = curl1;
                    l2 = tmp;
                }
            }
        }
        return l1;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) { // 分治
        int n = lists.size();
        int interval = 1;
        while(interval < n) {
            for(int i=0; i<n-interval; i+=2*interval) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        if(n) return lists[0];
        else return NULL;
    }
};