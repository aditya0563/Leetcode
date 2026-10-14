class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> row_max(n,vector<int>(n-2));

        for(int i=0;i<n;++i){
            for(int j=0;j<n-2;++j){
                int a=grid[i][j],b=grid[i][j+1],c=grid[i][j+2];
                row_max[i][j]=(a>b)?((a>c)?a:c):((b>c)?b:c);
            }
        }

        vector<vector<int>> res(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;++i){
            for(int j=0;j<n-2;++j){
                int a=row_max[i][j],b=row_max[i+1][j],c=row_max[i+2][j];
                res[i][j]=(a>b)?((a>c)?a:c):((b>c)?b:c);
            }
        }

        return res;
    }
};