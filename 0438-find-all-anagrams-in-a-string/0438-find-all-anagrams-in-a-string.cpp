class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) {
            return result;
        }
        
        vector<int> p_count(26, 0);
        vector<int> s_count(26, 0);
        
        for (int i = 0; i < p.length(); ++i) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }
        
        if (p_count == s_count) {
            result.push_back(0);
        }
        
        for (int i = p.length(); i < s.length(); ++i) {
            s_count[s[i] - 'a']++;
            s_count[s[i - p.length()] - 'a']--;
            
            if (p_count == s_count) {
                result.push_back(i - p.length() + 1);
            }
        }
        
        return result;
    }
};