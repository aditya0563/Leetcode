class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return nums;

        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;++i) vec[i]={i,nums[i]};

        sort(vec.begin(),vec.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.second>b.second;
        });
        sort(vec.begin(),vec.begin()+k);

        vector<int> res;
        for(int i=0;i<k;++i) res.push_back(vec[i].second);

        return res;
    }
};