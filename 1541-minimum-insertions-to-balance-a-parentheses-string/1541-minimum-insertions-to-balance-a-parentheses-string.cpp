class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int result=0,count=0,i=0;

        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }else{
                if(count>0){
                    count--;
                }else{
                    result++;
                }

                if(i+1<n&&s[i+1]==')'){
                    i+=2;
                }else{
                    result++;
                    i++;
                }
            }
        }

        return result+count*2;
    }
};