class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less_count=0,equal_count=0;
        
        for(int n:nums){
            if(n<target)less_count++;
            else if(n==target)equal_count++;
        }
        
        vector<int> res;
        res.reserve(equal_count);
        for(int i=0;i<equal_count;++i) res.push_back(less_count+i);
        
        return res;
    }
};