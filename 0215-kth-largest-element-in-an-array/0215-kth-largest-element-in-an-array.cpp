class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target=nums.size()-k;
        nth_element(nums.begin(),nums.begin()+target,nums.end());
        return nums[target];
    }
};