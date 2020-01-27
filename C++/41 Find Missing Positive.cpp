class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = 1;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if(*it < cur) continue;
            if(*it == cur) cur++;
            else return cur;
        }
        return cur;
    }
};