class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());

        vector<long long> power(nums.size());
        power[0] = 1;
        for(int i = 1; i<nums.size(); i++){
            power[i] = (power[i-1] * 2) % MOD;
        }

        long long count = 0;
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            if(nums[i] + nums[j] <= target){
                count = (count + power[j-i]) % MOD;
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
};