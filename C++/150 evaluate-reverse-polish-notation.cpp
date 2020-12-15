class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;
        for(auto& item: tokens) {
            if(isdigit(item[0]) || (item[0] == '-' && item.length() > 1)) { // negatives!
                s.push(atoi(item.c_str()));
            } else {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                if(item == "+") {
                    s.push(b+a);
                } else if(item == "-") {
                    s.push(b-a);
                } else if(item == "*") {
                    s.push(b*a);
                } else if(item == "/") {
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};