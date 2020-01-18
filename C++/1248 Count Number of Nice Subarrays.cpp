class Solution {
private:
    int prefixOdd[50001];
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        prefixOdd[1] = nums[0] % 2;
        for(int i=1; i<n; i++) 
            prefixOdd[i+1] = prefixOdd[i] + nums[i]%2;
        int cnt = 0;
        map<int, int> had;
        for(int i=1; i<=n; i++) { // Two Sum
            had[k + prefixOdd[i-1]]++;
            cnt += had[prefixOdd[i]];
        }
        return cnt;
    }
};