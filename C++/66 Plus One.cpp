class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ret;
        if(n == 0) {
            ret.push_back(1);
            return ret;
        }
        digits[n-1]++;
        int cur = n - 1;
        while(cur > 0 && digits[cur] > 9) {
            digits[cur] -= 10;
            digits[--cur]++;
        }
        if(digits[0] > 9) {
            ret.push_back(1);
            digits[0] -= 10;
        }
        for(int i=0; i<n; i++)
            ret.push_back(digits[i]);
        return ret;
    }
};