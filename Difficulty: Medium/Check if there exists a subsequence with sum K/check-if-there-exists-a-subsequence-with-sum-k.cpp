class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<bool> dp(k+1, false);
        dp[0] = true;
        
        for(int i =0; i<n; i++){
            for(int j = k; j >= arr[i]; j--){
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        return dp[k];
    }
};