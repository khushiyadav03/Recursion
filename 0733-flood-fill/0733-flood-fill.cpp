class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldcolor, int color){
        int m = image.size();
        int n = image[0].size();
        if(sr < 0 || sr >= m || sc < 0 || sc >= n) return;
        if(image[sr][sc] != oldcolor) return;
        image[sr][sc] = color;
        dfs(image, sr+1, sc, oldcolor, color);
        dfs(image, sr -1, sc, oldcolor, color);
        dfs(image, sr, sc+1, oldcolor, color);
        dfs(image, sr, sc-1, oldcolor, color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vec;
        int oldcolor = image[sr][sc];
        if(oldcolor == color) return image;
        dfs(image, sr, sc, oldcolor, color);
        return image;
    }
};