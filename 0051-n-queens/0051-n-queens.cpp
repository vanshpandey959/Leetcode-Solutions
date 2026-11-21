class Solution {
public:
    bool canWeFill(int row, int col, int n, vector<string>& board) {
        int dupRow = row;
        int dupCol = col;

        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--; col--;
        }

        row = dupRow; col = dupCol;

        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = dupRow; col = dupCol;

        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }

        return true;
    }

    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans) {
        if(n == col) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(canWeFill(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col+1, n ,board, ans);
                board[row][col] ='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++) {
            board[i] = s;
        }
        solve(0, n, board, ans);
        return ans;
    }
};