class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res=0,n=nums.size();

        for(int i=0;i<n;++i){
            bool seen[101]={};
            for(int j=i,alg=0;j<n;++j){
                alg += !seen[nums[j]];
                seen[nums[j]]=true;
                res+=alg*alg;
            }
        }

        return res;
    }
};