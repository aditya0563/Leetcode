class Solution {
public:
    void remove(string s, vector<string>& ans, int last_i, int last_j, char p1, char p2) {
        for (int count = 0, i = last_i; i < s.length(); ++i) {
            if (s[i] == p1) count++;
            else if (s[i] == p2) count--;
            
            if (count >= 0) continue;
            
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == p2 && (j == last_j || s[j - 1] != p2)) {
                    remove(s.substr(0, j) + s.substr(j + 1), ans, i, j, p1, p2);
                }
            }
            return;
        }
        
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        
        if (p1 == '(') {
            remove(reversed, ans, 0, 0, ')', '(');
        } else {
            ans.push_back(reversed);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s, ans, 0, 0, '(', ')');
        return ans;
    }
};