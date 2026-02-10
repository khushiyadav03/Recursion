class Solution {
  public:
    void solve(int idx, string curr, string &s, vector<string> &ans){
        if(idx == s.length()){
            if(curr.length() > 0){
                ans.push_back(curr);
            }
            return;
        }
        
        solve(idx + 1, curr + s[idx], s, ans);
        solve(idx + 1, curr, s, ans);
    }
    
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        string curr = "";
        solve(0, curr, s, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};