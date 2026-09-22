class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1;

        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };

        for (int i = k - 1; i < n; ++i) {
            if (i - k + 1 > last_end && isPalindrome(i - k + 1, i)) {
                count++;
                last_end = i;
            } else if (i - k > last_end && isPalindrome(i - k, i)) {
                count++;
                last_end = i;
            }
        }
        
        return count;
    }
};