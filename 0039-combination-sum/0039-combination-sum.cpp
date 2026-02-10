class Solution {
public:
    void solve(int idx, int target, vector<int>& curr, vector<int>& candidates, vector<vector<int>> &ans){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == n ||target < 0) return;
        curr.push_back(candidates[idx]);
        solve(idx, target-candidates[idx], curr, candidates, ans);
        curr.pop_back();
        solve(idx + 1, target, curr, candidates, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, curr, candidates, ans);
        return ans;
    }
};