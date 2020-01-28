// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1; 
        long long r = (long long)n + 1;
        while(l < r) {
            int mid = (l + r) / 2;
            short ret = guess(mid);
            switch(ret) {
                case 0: return mid;
                case -1:
                    r = mid;
                    break;
                case 1:
                    l = mid + 1;
                    break;
            }
        }
        return l;
    }
};