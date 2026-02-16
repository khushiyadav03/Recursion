class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<int> visited(v+1, false);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int i : adj[curr]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return ans;
    }
};