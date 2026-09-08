class Solution {
public:
    int countCommas(int n) {
        long long totalCommas = 0;
        long long base = 1000;
        while (n >= base) {
            totalCommas += (n - base + 1);
            base *= 1000;
        }
        
        return totalCommas;
    }
};