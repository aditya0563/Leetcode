class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,cur=0;
        for(int x:nums){
            if(x){
                cur++;
                if(cur>mx)mx=cur;
            }
            else cur=0;
        }
        return mx;
    }
};