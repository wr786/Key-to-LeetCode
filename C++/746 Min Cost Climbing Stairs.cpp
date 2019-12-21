class Solution {
private:
    int dp[1001] = {0};
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        for(int i=2; i<=len; i++)
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
        return dp[len];
    }
};