class Solution {
public:
    bool isValid(vector<string>& board, int row, int col){
        // column check
        for(int i = 0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }

        // upper left diagonal
        int r = row -1, c = col -1;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // upper right diagonal
        int r2 = row -1, c2 = col+1;
        while(r2 >= 0 && c2 >= 0){
            if(board[r2][c2] == 'Q') return false;
            r2--;
            c2++;
        }
        return true;
    }

    void solve(vector<string>& board, int n, int row, vector<vector<string>>& ans){
        if(row >= n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                solve(board, n, row+1, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(board, n, 0, ans);
        return ans;
    }
};