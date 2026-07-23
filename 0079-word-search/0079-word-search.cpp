class Solution {
public:
    bool help(vector<vector<char>>& b, string& w,int r ,int c,int& rs,int& cs,int idx){
        if(idx==w.length()) return true;
        if(r<0||c<0||r>=rs||c>=cs||b[r][c]!=w[idx]) return false;

        char temp=b[r][c];

        b[r][c]='#';
        bool found = help(b,w,r+1,c,rs,cs,idx+1) || help(b,w,r,c+1,rs,cs,idx+1) || help(b,w,r,c-1,rs,cs,idx+1) || help(b,w,r-1,c,rs,cs,idx+1);
        b[r][c]=temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();

        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                if(help(board,word,r,c,rows,cols,0)) return true;
            }
        }

        return false;
    }
};