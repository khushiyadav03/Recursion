class Solution {
public:
    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solve(string &s, int index, vector<string> &curr, vector<vector<string>> &ans){
        int n = s.length();
        if(index == n){
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < n; i++){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i - index + 1));
                solve(s, i+1, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>curr;
        vector<vector<string>> ans;
        solve(s, 0, curr, ans);
        return ans;
    }
};