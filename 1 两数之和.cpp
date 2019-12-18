#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ret;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            if(m[target-nums[i]]) {
                ret.push_back(m[target-nums[i]] - 1);
                ret.push_back(i);
                break;
            }
            m[nums[i]] = i+1; // excludes the SP situation of idx0
            // put it in the end to avoid rep check
        }
        return ret;
    }
};