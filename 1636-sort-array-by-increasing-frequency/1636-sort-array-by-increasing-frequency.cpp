class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int c[201]={0};
        for(int n:nums) c[n+100]++;
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int A=c[a+100];
            int B=c[b+100];
            return A==B? a>b:A<B;
        });

        return nums;
    }
};