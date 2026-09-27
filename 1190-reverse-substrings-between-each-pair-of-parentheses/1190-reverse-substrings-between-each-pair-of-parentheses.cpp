class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        vector<int> st; 
        st.reserve(n / 2);
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push_back(i);
            } else if (s[i] == ')') {
                int j = st.back();
                st.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        string result;
        result.reserve(n);
        int i = 0, dir = 1;
        
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dir = -dir;
            } else {
                result += s[i];
            }
            i += dir;
        }
        
        return result;
    }
};