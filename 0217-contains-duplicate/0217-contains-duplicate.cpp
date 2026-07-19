class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        for(int i=0;i<nums.size();i++){
            if(duplicate.count(nums[i])) return 1;
            duplicate.insert(nums[i]);
        }
        return 0;
    }
};