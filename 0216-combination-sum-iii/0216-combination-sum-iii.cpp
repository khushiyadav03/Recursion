class Solution {
public:
    void solve(int start,
               int k,
               int sum,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        if (k == 0 && sum == 0) {
            ans.push_back(curr);
            return;
        }
        if (k == 0 || sum < 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            // if number is bigger than remaining sum, stop
            if (i > sum) break;

            curr.push_back(i);
            solve(i + 1, k - 1, sum - i, curr, ans);
            curr.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, k, n, curr, ans);
        return ans;
    }
};
