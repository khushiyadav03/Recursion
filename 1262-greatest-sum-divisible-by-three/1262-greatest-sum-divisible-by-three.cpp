class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for(int a : nums)
        for(int b : vector<int> (dp))
            dp[(a + b) % 3] = max(dp[(a + b) % 3], (a + b));
        return dp[0];
    }
};