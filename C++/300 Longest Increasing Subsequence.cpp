class Solution {
private:
    vector<int> dp;
    int ans = 0;
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0) return 0;
        for(int i=0; i<len; i++) {
            dp.push_back(1);
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};