// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0) return 1; // bug-free
        long long l = 1, r = (long long)n + 1, ans = n; // l..r // to prevent overflow
        while(l < r) {
            long long mid = (l + r) / 2; 
            if(isBadVersion(mid)) {
                ans = min(ans, mid);
                r = mid;
            }
            else l = mid + 1;
        }
        return ans;
    }
};