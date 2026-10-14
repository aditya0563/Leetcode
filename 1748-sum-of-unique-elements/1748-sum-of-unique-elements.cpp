class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int count[101]={0};

        for(int x:nums) count[x]++;

        int sum=0;
        for(int i=1;i<=100;++i){
            if(count[i]==1) sum+=i;
        }

        return sum;
    }
};