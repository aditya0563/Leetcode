class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            degree += (26 - (s[i]-'a')) * (i + 1);
        }
        
        return degree;
    }
};