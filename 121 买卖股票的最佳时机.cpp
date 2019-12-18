class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minV = INT_MAX, maxP = 0;
        for(int i=0; i<len; i++) {
            minV = min(minV, prices[i]);
            maxP = max(maxP, prices[i] - minV);
        }
        return maxP;
    }
};