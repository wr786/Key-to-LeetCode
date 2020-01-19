impl Solution {
    pub fn print_vertically(s: String) -> Vec<String> {
        let mut ret : Vec<String> = Vec::new();
        let mut maxlen = 0;
        for word in s.split_whitespace() {
            if word.len() > maxlen {
                maxlen = word.len();
            }
        }
        for i in 0..maxlen {
            let mut curcol = String::new();
            for word in s.split_whitespace() {
                if(word.len() > i) {
                    curcol.push_str(&word[i..i+1]);
                } else {
                    curcol = curcol + " ";  
                }
            }
            let len = curcol.len();
            let mut cnt = 0;
            for ch in curcol.chars().rev() {
                if(ch != ' ') {
                    break;
                }
                cnt = cnt + 1;
            }
            curcol = curcol[0..len-cnt].to_string();
            ret.push(curcol);
        }
        return ret;
    }
}