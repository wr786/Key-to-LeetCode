class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)  {
            int addPos = (nums[i] - 1) % n;
            nums[addPos] += n;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(nums[i] <= n)
                ans.push_back(i+1);
        return ans;
    }
};