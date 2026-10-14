class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count[101]={0};
        int ans=0;
        for(int x:nums) ans+=count[x]++;
        return ans;
    }
};