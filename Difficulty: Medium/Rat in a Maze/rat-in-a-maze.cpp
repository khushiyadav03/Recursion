class Solution {
public:

    void solve(int row, int col, vector<vector<int>>& maze, int n, vector<vector<bool>>& visited, string& path, vector<string>& ans) {
        // Base case
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[row][col] = true;

        // Down
        if (row + 1 < n && maze[row + 1][col] == 1 && !visited[row + 1][col]) {
            path.push_back('D');
            solve(row + 1, col, maze, n, visited, path, ans);
            path.pop_back();
        }

        // Left
        if (col - 1 >= 0 && maze[row][col - 1] == 1 && !visited[row][col - 1]) {
            path.push_back('L');
            solve(row, col - 1, maze, n, visited, path, ans);
            path.pop_back();
        }

        // Right
        if (col + 1 < n && maze[row][col + 1] == 1 && !visited[row][col + 1]) {
            path.push_back('R');
            solve(row, col + 1, maze, n, visited, path, ans);
            path.pop_back();
        }

        // Up
        if (row - 1 >= 0 && maze[row - 1][col] == 1 && !visited[row - 1][col]) {
            path.push_back('U');
            solve(row - 1, col, maze, n, visited, path, ans);
            path.pop_back();
        }

        visited[row][col] = false;  // Backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();
        vector<string> ans;

        // If start or end blocked
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";

        solve(0, 0, maze, n, visited, path, ans);

        return ans;
    }
};
