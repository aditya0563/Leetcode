class Solution {
public:
    int ss(int n){
        int sum=0;
        while(n){
            int d=n%10;
            sum+=d*d;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow=n,fast=n;
        while(true){
            slow=ss(slow);
            fast=ss(ss(fast));
            if(fast==1) return true;
            if(slow==fast) return false;
        }
        return false;
    }
};