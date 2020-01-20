class Solution {
private:
    set<int> vis;
    static inline int calc(int x) {
        int ret = 0;
        while(x) {
            ret += (x%10) * (x%10);
            x /= 10;
        }
        return ret;
    }
public:
    bool isHappy(int n) {
        if(n == 1) {
            return true;
        } else if(vis.count(n)) {
            return false;
        } else{
            vis.insert(n);
            return isHappy(calc(n));
        }
    }
};