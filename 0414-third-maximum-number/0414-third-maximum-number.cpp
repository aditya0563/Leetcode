class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long m1=LLONG_MIN,m2=LLONG_MIN,m3=LLONG_MIN;
        
        for(int x:nums){
            if(x==m1||x==m2||x==m3) continue;
            if(x>m1){
                m3=m2;
                m2=m1;
                m1=x;
            }else if(x>m2){
                m3=m2;
                m2=x;
            }else if(x>m3) m3=x;
        }
        
        return m3==LLONG_MIN?m1:m3;
    }
};