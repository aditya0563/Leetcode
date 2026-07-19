class Solution {
public:
    int helper(vector<int>& nums,int start,int end,int& target){
        if(start>end) return -1;
        int mid=start+(end-start)/2;

        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return helper(nums,mid+1,end,target);
        else return helper(nums,start,mid-1,target);

        return -1;
    }

    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};