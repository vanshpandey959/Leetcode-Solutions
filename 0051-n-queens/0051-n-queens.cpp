class Solution {
public:
    // bool canWeFill(int row, int col, int n, vector<string>& board) {
    //     int dupRow = row;
    //     int dupCol = col;

    //     while(row >= 0 && col >= 0) {
    //         if(board[row][col] == 'Q') return false;
    //         row--; col--;
    //     }

    //     row = dupRow; col = dupCol;

    //     while(col >= 0) {
    //         if(board[row][col] == 'Q') return false;
    //         col--;
    //     }

    //     row = dupRow; col = dupCol;

    //     while(row < n && col >= 0) {
    //         if(board[row][col] == 'Q') return false;
    //         col--;
    //         row++;
    //     }

    //     return true;
    // }

    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& left, vector<int>& lowerDiag, vector<int>& upperDiag) {
        if(n == col) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(left[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[(n-1) + (col-row)] == 0) {
                board[row][col] = 'Q';
                left[row] = 1;
                lowerDiag[row+col] = 1;
                upperDiag[(n-1) + (col-row)] = 1;
                solve(col+1, n ,board, ans, left, lowerDiag, upperDiag);
                left[row] = 0;
                lowerDiag[row+col] = 0;
                upperDiag[(n-1) + (col-row)] = 0;
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

        vector<int> left(n, 0);
        vector<int> lowerDiag(2*n-1, 0);
        vector<int> upperDiag(2*n-1, 0);

        solve(0, n, board, ans, left, lowerDiag, upperDiag);
        return ans;
    }
};