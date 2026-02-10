class Solution {
public:
    void solve(int idx, int target, vector<int> &curr, vector<int> &candidates, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0) return;

        for(int i = idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            curr.push_back(candidates[i]);
            solve(i+1, target - candidates[i], curr, candidates, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        solve(0, target, curr, candidates, ans);
        return ans;
    }
};