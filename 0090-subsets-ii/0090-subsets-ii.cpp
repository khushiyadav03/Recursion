class Solution {
public:
    void solve(int index, vector<int> &curr, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        solve(index +1, curr, nums, ans);
        curr.pop_back();
        solve(index+1, curr, nums, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, nums, ans);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};