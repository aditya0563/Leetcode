class Solution {
public:
    double myPow(double x, int n) {
        long long p=n;
        if(p<0){
            p=-p;
            x=1.0/x;
        }

        double ans=1.0;

        while(p>0){
            if(p%2==1) ans=ans*x;
            x*=x;
            p/=2;
        }

        return ans;
    }
};