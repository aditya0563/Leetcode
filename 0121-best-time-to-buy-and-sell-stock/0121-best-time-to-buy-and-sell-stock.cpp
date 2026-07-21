class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0, Min = prices[0];
        for(int i=1;i<prices.size();i++){
            Min = min(Min,prices[i]);
            res = max(res,prices[i]-Min);
        }
        return res;
    }
};