class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";

        string res(num,'0');
        int c9=sum/9;
        int r=sum%9;

        for(int i=0;i<c9;++i) res[i]='9';
        if(c9<num && r>0) res[c9]=r+'0';

        return res;
    }
};