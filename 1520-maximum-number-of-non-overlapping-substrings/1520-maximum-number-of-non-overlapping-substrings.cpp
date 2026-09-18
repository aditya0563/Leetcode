class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }
        
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            
            int left = first[i];
            int right = last[i];
            bool valid = true;
            
            for (int j = left; j <= right; ++j) {
                int idx = s[j] - 'a';
                if (first[idx] < left) {
                    valid = false;
                    break;
                }
                right = max(right, last[idx]);
            }
            
            if (valid) {
                intervals.push_back({left, right});
            }
        }
        
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return (a.second - a.first) < (b.second - b.first);
        });
        
        vector<string> result;
        int prev_end = -1;
        
        for (const auto& interval : intervals) {
            if (interval.first > prev_end) {
                result.push_back(s.substr(interval.first, interval.second - interval.first + 1));
                prev_end = interval.second;
            }
        }
        
        return result;
    }
};