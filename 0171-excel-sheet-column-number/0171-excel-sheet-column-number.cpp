class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(char c:columnTitle) res=res*26+(c & 31);
        return res;
    }
};