class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";

        auto minmax=minmax_element(strs.begin(),strs.end());
        const string& first=*minmax.first;
        const string& last=*minmax.second;

        int i=0;
        while(i<first.length() && i<last.length() && first[i]==last[i]) i++;

        return first.substr(0,i);
    }
};