class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long k=(long long)k1+k2;
        vector<int> count(100001,0);
        long long total_diff=0;
        int max_diff=0;

        for(int i=0;i<n;++i){
            int diff=abs(nums1[i]-nums2[i]);
            if(diff>0){
                count[diff]++;
                max_diff=max(max_diff,diff);
                total_diff+=diff;
            }
        }

        if(k>=total_diff) return 0;

        for(int i=max_diff;i>0&&k>0;--i){
            if(count[i]>0){
                long long take=min((long long)count[i],k);
                count[i]-=take;
                count[i-1]+=take;
                k-=take;
            }
        }

        long long result=0;
        for(long long i=1;i<=max_diff;++i){
            if(count[i]>0){
                result+=i*i*count[i];
            }
        }

        return result;
    }
};