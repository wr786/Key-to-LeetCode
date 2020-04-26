class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int> > pq;
        int ret = 0;
        for(auto& item: nums) pq.push(item);
        while(k--) {
            ret = (pq.top());
            pq.pop();
        }
        return ret;
    }
};