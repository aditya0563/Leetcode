class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res;
        int n=grid[0].size();
        bool a=true;

        for(int i=0;i<grid.size();++i){
            for(int j=0;j<n;++j){
                if(a){
                    res.push_back(grid[i][(i&1)?n-1-j:j]);
                }
                a=!a;
            }
        }

        return res;
    }
};