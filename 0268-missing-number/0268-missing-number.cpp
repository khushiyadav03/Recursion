class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i<nums.size()+1; i++){
            x ^= i;
        }

        for(int n : nums){
            x ^= n;
        }
        return x;
    }
};