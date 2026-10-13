class Solution {
public:
    string addBinary(string a, string b) {
        int n=max(a.length(),b.length());
        string res(n+1,'0');

        int i=a.length()-1;
        int j=b.length()-1;
        int k=n;
        int c=0;

        while(i>=0||j>=0||c>0){
            
            int s=c;
            if(i>=0) s+=a[i--]-'0';
            if(j>=0) s+=b[j--]-'0';

            res[k--]=(s&1)+'0';
            c=s>>1;
        }

        return res.substr(k+1);
    }
};