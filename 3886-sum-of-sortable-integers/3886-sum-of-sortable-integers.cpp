class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        
        auto check=[&](int k){
            int prev_max=-1;
            
            for(int i=0;i<n;i+=k){
                int L=i;
                int R=i+k-1;
                int drops=0;
                int drop_idx=-1;
                
                for(int j=L;j<R;++j){
                    if(nums[j]>nums[j+1]){
                        if(++drops>1)return false;
                        drop_idx=j;
                    }
                }
                
                if(drops==1&&nums[R]>nums[L])return false;
                
                int curr_min=(drops==0)?nums[L]:nums[drop_idx+1];
                int curr_max=(drops==0)?nums[R]:nums[drop_idx];
                
                if(prev_max>curr_min)return false;
                
                prev_max=curr_max;
            }
            return true;
        };

        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                if(check(i))ans+=i;
                if(i*i!=n){
                    if(check(n/i))ans+=(n/i);
                }
            }
        }
        
        return ans;
    }
};