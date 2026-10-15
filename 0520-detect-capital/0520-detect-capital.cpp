class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for(char c:word) if(c>='A'&&c<='Z') count++;
        if(count==0||count==word.length()) return true;
        return count==1&&word[0]>='A'&&word[0]<='Z';
    }
};