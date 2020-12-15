class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> s;
        for(size_t i=0; i<height.size(); i++) {
            while(!s.empty() && height[i] > height[s.top()]) {
                int mid = s.top(); s.pop();
                if(s.empty()) break;    // 不能形成一个凹槽
                int w = i - s.top() - 1;    // 中间凹槽的宽度
                int h = min(height[i], height[s.top()]) - height[mid];
                sum += w * h;
            }
            s.push(i);
        }
        return sum;
    }
};