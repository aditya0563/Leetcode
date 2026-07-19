class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for (auto& [num, freq] : mp) {
            bucket[freq].push_back(num);
        }

        vector<int> result;
        for (int i = n; k > 0 && i >= 0; i--) {
            for (int j = bucket[i].size() - 1; j >= 0 && k > 0; j--) {
                result.push_back(bucket[i][j]);
                k--;
            }
        }
        return result;
    }
};