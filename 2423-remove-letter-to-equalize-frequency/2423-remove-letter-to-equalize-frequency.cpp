class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> count(26,0);

        for(char c:word) count[c-'a']++;

        for(int i=0;i<26;++i){
            if(count[i]>0){
                count[i]--;
                int first_freq=0;
                bool is_valid=true;

                for(int j=0;j<26;++j){
                    if(count[j]==0)continue;
                    if(first_freq==0) first_freq=count[j];
                    else if(count[j]!=first_freq){
                        is_valid=false;
                        break;
                    }
                }

                if(is_valid) return true;
                count[i]++;
            }
        }

        return false;
    }
};