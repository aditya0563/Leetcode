class Solution {
public:
    struct Interval {
        int start;
        int end;
        int weight;
        int id;
    };

    struct State {
        long long score = 0;
        int len = 0;
        int ids[4] = {0};
    };

    static bool isBetter(const State& a, const State& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }
        for (int i = 0; i < min(a.len, b.len); ++i) {
            if (a.ids[i] != b.ids[i]) {
                return a.ids[i] < b.ids[i];
            }
        }
        return a.len < b.len;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> inters(n);
        
        for (int i = 0; i < n; ++i) {
            inters[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(inters.begin(), inters.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        
        vector<vector<State>> dp(n + 1, vector<State>(5));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                State skip = dp[i + 1][k];
                
                int low = i + 1, high = n - 1, nextIdx = n;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (inters[mid].start > inters[i].end) {
                        nextIdx = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                
                State take = dp[nextIdx][k - 1];
                take.score += inters[i].weight;
                
                take.ids[take.len++] = inters[i].id;
                sort(take.ids, take.ids + take.len);
                
                if (isBetter(take, skip)) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = skip;
                }
            }
        }
        
        return vector<int>(dp[0][4].ids, dp[0][4].ids + dp[0][4].len);
    }
};