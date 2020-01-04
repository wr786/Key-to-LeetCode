class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
            ans ^= *it;
        return ans;
    }
};