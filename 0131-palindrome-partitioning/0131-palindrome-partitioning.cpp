class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    void backtrack(int start, const string& s, vector<string>& curr, vector<vector<string>>& res) {
        if(start == s.length()) {
            res.push_back(curr);
            return;
        }
        for(int i = start; i < s.length(); ++i) {
            if(isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                backtrack(i + 1, s, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(0, s, curr, res);
        return res;
    }
};