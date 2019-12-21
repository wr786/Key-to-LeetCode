/*
执行用时 :0 ms, 在所有 rust 提交中击败了100.00% 的用户
内存消耗 :2 MB, 在所有 rust 提交中击败了100.00%的用户
*/
use std::collections::VecDeque;
impl Solution {
    pub fn is_valid(s: String) -> bool {
        if(s == "") {return true;}
        let mut dq : VecDeque<char> = VecDeque::new();
        dq.push_front('#'); // to prevent special cases such as: )()
        for c in s.chars() {
            if(c == ')') {
                if(dq[0] != '(') {
                    return false;
                } else {
                    dq.pop_front();
                }
            } else if(c == ']') {
                if(dq[0] != '[') {
                    return false;
                } else {
                    dq.pop_front();
                }
            } else if(c == '}') {
                if(dq[0] != '{') {
                    return false;
                } else {
                    dq.pop_front();
                }
            } else {
                dq.push_front(c);
            }
        }
        if(dq[0] != '#') {
            return false;
        }
        return true;
    }
}