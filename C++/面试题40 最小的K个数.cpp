class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ret;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto item: arr) pq.push(item);
        while(k--) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};