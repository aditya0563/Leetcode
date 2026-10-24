class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int N = n + k - 1;
        int K = 2 * k;
        
        if (K > N) return 0;
        
        long long num = 1;
        for (int i = 1; i <= K; ++i) {
            num = (num * (N - i + 1)) % MOD;
        }
        
        long long denom = 1;
        for (int i = 1; i <= K; ++i) {
            denom = (denom * i) % MOD;
        }
        
        long long base = denom;
        long long exp = MOD - 2;
        long long inv = 1;
        
        while (exp > 0) {
            if (exp % 2 == 1) inv = (inv * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        
        return (num * inv) % MOD;
    }
};