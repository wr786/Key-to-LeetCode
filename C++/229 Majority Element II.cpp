class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        if(n == 0) return ret;
        sort(nums.begin(), nums.end());
        int left = 0;
        for(int i=1; i<n; i++) {
            if(nums[i] != nums[left]) {
                if(i - left > n / 3) ret.push_back(nums[left]);
                left = i;
            }
        }   
        if(n - left > n / 3) ret.push_back(nums[left]);
        return ret;
    }
};