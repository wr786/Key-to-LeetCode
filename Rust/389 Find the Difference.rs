use std::collections::HashMap;
/*
    执行用时 :0 ms, 在所有 rust 提交中击败了100.00% 的用户
    内存消耗 :2 MB, 在所有 rust 提交中击败了100.00%的用户
*/
impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let lowerAlphas: String = String::from("abcdefghijklmnopqrstuvwxyz");
        let mut dict: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            match(dict.get(&c)) {
                Some(&val) => dict.insert(c, val+1),
                _ => dict.insert(c, 1),
            };
        }
        let mut dict2: HashMap<char, i32> = HashMap::new();
        for c in t.chars() {
            match(dict2.get(&c)) {
                Some(&val) => dict2.insert(c, val+1),
                _ => dict2.insert(c, 1),
            };
        }
        for c in lowerAlphas.chars() {
            match(dict2.get(&c)) {
                Some(&val2) => {
                    match(dict.get(&c)) {
                        Some(&val) => if(val != val2) {return c;}
                        _ => return c,
                    }
                },
                _ => (),
            };
        }
        return ' ';
    }
}