class Solution {
public:
const string pad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(int idx, const string& digits, string& curr, vector<string>& res) {
        if(idx == digits.length()) {
            res.push_back(curr);
            return;
        }
        for(char c : pad[digits[idx] - '0']) {
            curr.push_back(c);
            backtrack(idx + 1, digits, curr, res);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string curr = "";
        backtrack(0, digits, curr, res);
        return res;
    }
};