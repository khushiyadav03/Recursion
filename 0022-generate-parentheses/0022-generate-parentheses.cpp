class Solution {
public:
    void solve(int open, int close, int n, vector<string>& ans, string curr){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            solve(open + 1, close, n, ans, curr + "(");
        }
        if(close < open){
            solve(open, close + 1, n, ans, curr + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, ans, "");
        return ans;
    }
};