class Solution {
public:
    void help(vector<int>& n,int start,int& size,vector<vector<int>>& ans){
        if(start==size){
            ans.push_back(n);
            return;
        }

        for(int i=start;i<size;++i){
            swap(n[start],n[i]);
            help(n,start+1,size,ans);
            swap(n[start],n[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        help(nums,0,n,ans);
        return ans;
    }
};