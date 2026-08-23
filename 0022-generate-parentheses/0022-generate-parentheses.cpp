class Solution {
public:
void backtrack(int openN, int closedN, int n, string& current, vector<string>& res) {
        if(openN == n && closedN == n) {
            res.push_back(current);
            return;
        }
        if(openN < n) {
            current.push_back('(');
            backtrack(openN + 1, closedN, n, current, res);
            current.pop_back();
        }
        if(closedN < openN) {
            current.push_back(')');
            backtrack(openN, closedN + 1, n, current, res);
            current.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current = "";
        backtrack(0, 0, n, current, res);
        return res;
    }
};