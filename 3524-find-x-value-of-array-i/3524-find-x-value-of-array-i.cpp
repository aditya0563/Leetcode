class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> new_dp(k, 0);
            long long current = num % k;
            
            new_dp[current] += 1;
            
            for (int i = 0; i < k; ++i) {
                if (dp[i] > 0) {
                    new_dp[(i * current) % k] += dp[i];
                }
            }
            
            for (int i = 0; i < k; ++i) {
                result[i] += new_dp[i];
                dp[i] = new_dp[i];
            }
        }
        
        return result;
    }
};