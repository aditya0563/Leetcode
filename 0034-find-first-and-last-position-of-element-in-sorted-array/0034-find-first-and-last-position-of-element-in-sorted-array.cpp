class Solution {
public:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                bound = mid;
                if(isFirst) high = mid - 1;
                else low = mid + 1;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return bound;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if(first == -1) return {-1, -1};
        int last = findBound(nums, target, false);
        return {first, last};
    }
};