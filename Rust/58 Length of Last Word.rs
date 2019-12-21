/*
	0ms 						defeated 100%;
	1.9MB 						defeated 100%;
*/
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        for str in s.split_whitespace().rev() {
            return str.len() as i32;
        }
        return 0;
    }
}