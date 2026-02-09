class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] <= nums[i - 1]){
                int x = (nums[i-1] + 1) - nums[i];
                count += x;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return count;
    }
};