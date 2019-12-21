/*
执行用时 :0 ms, 在所有 rust 提交中击败了100.00% 的用户
内存消耗 :2.3 MB, 在所有 rust 提交中击败了100.00%的用户
*/
impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let len: i32 = nums.len() as i32;
        if(len <= 1) {return true;}
        let mut end: i32 = len - 1;
        for (i, x) in nums.iter().enumerate().rev() {
            if(i as i32 + x >= end) {
                end = i as i32;
            }
        }
        end == 0
    }
}