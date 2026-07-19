class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()==0) return res;

        unordered_map<string,vector<string>> mp;

        for(string org:strs){
            string sorted=org;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(org);
        }

        for(auto& it:mp) res.push_back(it.second);

        return res;
    }
};