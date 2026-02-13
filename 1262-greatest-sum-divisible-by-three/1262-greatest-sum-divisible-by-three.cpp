class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for(int i = 0; i<nums.size(); i++){
            int currNum = nums[i];
            vector<int> prev(dp);
            for(int j = 0; j<3; j++){
                int newSum = currNum + prev[j];
                dp[newSum % 3] = max(dp[newSum % 3], newSum);
            }
        }
        return dp[0];
    }
};