class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            int reversedAlphabetPosition = 26 - (s[i] - 'a');
            int stringPosition = i + 1;
            degree += reversedAlphabetPosition * stringPosition;
        }
        return degree;
    }
};