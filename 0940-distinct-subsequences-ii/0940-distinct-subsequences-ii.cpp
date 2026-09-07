class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<long long> endsWith(26, 0);
        long long total = 0; 
        
        for (char c : s) {
            int index = c - 'a';
            long long old_val = endsWith[index];
            long long new_val = (total + 1) % MOD;
            
            endsWith[index] = new_val;           
            total = (total - old_val + new_val + MOD) % MOD;
        }
        
        return total;
    }
};