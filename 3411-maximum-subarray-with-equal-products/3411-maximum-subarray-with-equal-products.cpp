class Solution {
public:
    long long gcd(long long a,long long b){
        while(b!=0){
            long long t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    
    long long lcm(long long a,long long b){
        return(a/gcd(a,b))*b;
    }

    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        long long limit=100000LL;
        for(int i=0;i<n;i++){
            long long p=1,g=0,l=1;
            for(int j=i;j<n;j++){
                p*=nums[j];
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                if(p==g*l){
                    ans=max(ans,j-i+1);
                }
                if(p>limit){
                    break;
                }
            }
        }
        return ans;
    }
};