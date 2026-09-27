class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e9);
        int ans = 1e9;
        int best_so_far = 1e9;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int current_len = right - left + 1;
                if (left > 0 && min_len[left - 1] != 1e9) {
                    ans = min(ans, current_len + min_len[left - 1]);
                }
                best_so_far = min(best_so_far, current_len);
            }
            
            min_len[right] = best_so_far;
        }

        return ans == 1e9 ? -1 : ans;
    }
};