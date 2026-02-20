class Solution {
  public:
    bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& adj){
        for(int n : adj[node]){
            if(color[n] == col) return false;
        }
        return true;
    }
    
    bool solve(int node, vector<int>& color, vector<vector<int>>& adj, int m, int v){
        if(node == v) return true;
        
        for(int col = 1; col <= m; col++){
    if(isSafe(node, col, color, adj)) {
        color[node] = col;

        if(solve(node+1, color, adj, m, v)) 
            return true;

        color[node] = 0;  // backtrack
    }
}
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for(auto& e : edges){
            int u = e[0];
            int w = e[1];
            
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        vector<int> color(v, 0);
        return solve(0, color, adj, m, v);
    }
};