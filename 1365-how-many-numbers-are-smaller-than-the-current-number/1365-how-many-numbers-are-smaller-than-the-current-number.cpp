class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101]={0};
        for(int n:nums) count[n]++;
        for(int i=1;i<=100;++i) count[i]+=count[i-1];
        for(int& n:nums) n=(n==0)? 0:count[n-1];
        return nums;
    }
};