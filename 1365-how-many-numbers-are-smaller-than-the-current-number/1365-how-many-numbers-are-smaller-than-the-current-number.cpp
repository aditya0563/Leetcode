class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[102]={0};
        for(int x:nums) count[x+1]++;
        for(int i=1;i<=100;++i) count[i]+=count[i-1];
        for(int& x:nums) x=count[x];
        return nums;
    }
};