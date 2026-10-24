class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word_idx=1;
        int j=0;
        
        for(char c:sentence){
            if(c==' '){
                word_idx++;
                j=0; 
            }
            else if(j != -1 && c==searchWord[j]){
                if(++j == searchWord.length()) return word_idx;
            }
            else j=-1; 
        }
        
        return -1;
    }
};