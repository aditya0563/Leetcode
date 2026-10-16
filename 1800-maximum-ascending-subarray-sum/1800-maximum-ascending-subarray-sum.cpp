class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ms=nums[0];
        int cs=nums[0];

        for(int i=1;i<nums.size();++i){
            cs=(nums[i]>nums[i-1])? cs+nums[i]:nums[i];
            if(cs>ms)ms=cs;
        }

        return ms;
    }
};