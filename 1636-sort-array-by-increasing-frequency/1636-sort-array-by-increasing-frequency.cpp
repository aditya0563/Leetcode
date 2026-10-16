class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int c[201]={0};
        for(int n:nums)c[n+100]++;

        int n=nums.size();
        vector<vector<int>> buc(n+1);
        for(int i=100;i>=-100;--i) if(c[i+100]>0) buc[c[i+100]].push_back(i);

        int idx=0;
        for(int a=1;a<=n;++a){
            for(int val:buc[a]){
                for(int k=0;k<a;++k)nums[idx++]=val;
            }
        }

        return nums;
    }
};