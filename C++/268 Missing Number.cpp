class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int m = n * (n + 1) / 2;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
            m -= *it;
        return m;
    }
};