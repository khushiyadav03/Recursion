class Solution {
public:
    void solve(int row, int n,
               vector<string>& board,
               vector<bool>& cols,
               vector<bool>& diag,
               vector<bool>& antiDiag,
               vector<vector<string>>& ans) {

        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {

            int d = row - col + (n - 1);   // main diagonal index
            int ad = row + col;            // anti-diagonal index

            if(cols[col] || diag[d] || antiDiag[ad])
                continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = true;
            diag[d] = true;
            antiDiag[ad] = true;

            solve(row + 1, n, board, cols, diag, antiDiag, ans);

            // Backtrack
            board[row][col] = '.';
            cols[col] = false;
            diag[d] = false;
            antiDiag[ad] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> diag(2*n - 1, false);
        vector<bool> antiDiag(2*n - 1, false);

        solve(0, n, board, cols, diag, antiDiag, ans);

        return ans;
    }
};
