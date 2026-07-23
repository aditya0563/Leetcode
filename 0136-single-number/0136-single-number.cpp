class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int op=0,n=nums.size();
        for(int i=0;i<n;i++) op^=nums[i];
        return op;
    }
};