class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth = 0;
        for(vector<int> cust : accounts){
            int current = 0;
            for(int bank : cust){
                current += bank;
            }
            wealth = max(wealth, current);
        }
        return wealth;
    }
};