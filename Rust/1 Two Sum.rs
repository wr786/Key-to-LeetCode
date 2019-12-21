/*
执行用时 :0 ms, 在所有 rust 提交中击败了100.00% 的用户
内存消耗 :2.8 MB, 在所有 rust 提交中击败了61.14%的用户
*/
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut ret : Vec<i32> = Vec::new();
        let mut map = HashMap::new();
        for (i, x) in nums.iter().enumerate() {
            match(map.get(&(target-x))) {
                Some(&index) => {
                    ret.push(index);
                    ret.push(i as i32);
                    break;
                },
                _ => (),
            }
            map.insert(x, i as i32);
        }        
        return ret;
    }
}