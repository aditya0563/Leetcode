class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count[101]={0};
        int ans=0;

        for(int x:nums){
            if(x-k>=1 )ans+=count[x-k];
            if(x+k<=100) ans+=count[x+k];
            count[x]++;
        }

        return ans;
    }
};