class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        int maxOverlaps = 0;
        unordered_map<int, int> shiftCounts;
        
        for (const auto& p1 : ones1) {
            for (const auto& p2 : ones2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                
                int shiftId = (dx + n) * 100 + (dy + n);
                shiftCounts[shiftId]++;
                maxOverlaps = max(maxOverlaps, shiftCounts[shiftId]);
            }
        }
        
        return maxOverlaps;
    }
};