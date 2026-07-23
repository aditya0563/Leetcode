class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        ans[0]=0;
        int twos=1;
        for(int i=1;i<=n;i++){
            if(i==twos*2) twos*=2;
            ans[i]=ans[i-twos]+1;
        }
        return ans;
    }
};