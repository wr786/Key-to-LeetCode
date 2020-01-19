class Solution {
private:
    struct Interval {
        int left;
        int right;
    } itv[10001];
    static bool cmp (Interval A, Interval B) {
        if(A.left != B.left) return A.left < B.left;
        else return A.right < B.right;
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        for(int i=0; i<=n; i++) {
            itv[i].left = max(0, i-ranges[i]);
            itv[i].right = min(n, i+ranges[i]);
        }
        sort(itv, itv+n+1, cmp);
        int leftmost = 0, cnt = 0, rightmost = 0;
        for(int i=0; i<=n; i++) {
            if(leftmost >= itv[i].left) {
                rightmost = max(rightmost, itv[i].right);
            } else { // 这一处超了
                if(rightmost > leftmost) {
                    leftmost = rightmost;
                    rightmost = 0;
                    cnt++;
                    i--;
                } else {
                    return -1;
                }
            }
        }
        if(rightmost > leftmost) cnt++;
        return cnt;
    }
};