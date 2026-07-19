class Solution {
public:
    void helper(int n,int open,int close,int idx,string& temp, vector<string>& ans){
        if(idx==2*n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
            temp[idx]='(';
            helper(n,open+1,close,idx+1,temp,ans);
        }

        if(close<open){
            temp[idx]=')';
            helper(n,open,close+1,idx+1,temp,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp(2*n,' ');

        helper(n,0,0,0,temp,ans);

        return ans;
    }
};