class Solution {
private:
    map<int, int> cnt;
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            cnt[nums[i]]++;
            if(cnt[nums[i]] > n/2) return nums[i];
        }
        return nums[0];
    }
};