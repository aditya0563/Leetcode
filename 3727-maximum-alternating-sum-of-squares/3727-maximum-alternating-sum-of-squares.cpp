class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        int k=n/2;

        nth_element(nums.begin(),nums.begin()+k,nums.end(),[](int a,int b){
            return abs(a)<abs(b);
        });

        long long max_score=0;

        for(int i=0;i<k;++i) max_score-=1LL*nums[i]*nums[i];
        for(int i=k;i<n;++i) max_score+=1LL*nums[i]*nums[i];

        return max_score;
    }
};