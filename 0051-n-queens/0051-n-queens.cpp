class Solution {
public:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res, vector<bool>& col, vector<bool>& posDiag, vector<bool>& negDiag) {
        if(r == n) {
            res.push_back(board);
            return;
        }
        for(int c = 0; c < n; ++c) {
            if(col[c] || posDiag[r + c] || negDiag[r - c + n]) continue;
            col[c] = posDiag[r + c] = negDiag[r - c + n] = true;
            board[r][c] = 'Q';
            backtrack(r + 1, n, board, res, col, posDiag, negDiag);
            col[c] = posDiag[r + c] = negDiag[r - c + n] = false;
            board[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false), posDiag(2 * n, false), negDiag(2 * n, false);
        backtrack(0, n, board, res, col, posDiag, negDiag);
        return res;
    }
};