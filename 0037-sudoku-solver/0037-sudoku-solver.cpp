class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch){
        // row check
        for(int j = 0; j<9; j++){
            if(board[row][j] == ch){
                return false;
            }
        }

        // col check
        for(int i = 0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
        }

        // 3x3 matrix check
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[startrow + i][startcol + j] == ch){
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isSafe(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board)) return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};