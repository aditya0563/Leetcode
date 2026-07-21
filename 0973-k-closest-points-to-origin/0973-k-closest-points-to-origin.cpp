class Solution {
public:
    static int square(vector<int>& point){
        int x=point[0],y=point[1];
        return x*x+y*y;
    }

    static bool compare(vector<int>& a,vector<int>& b){
        return square(a)<square(b);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(),points.begin()+k,points.end(),compare);
        vector<vector<int>> res;
        for(int i=0;i<k;i++) res.push_back(points[i]);
        return res;
    }
};