class Solution {
public:
    void dfs(int index, long res, long prev, string expr, string& num, int target, vector<string>& ans){
        if(index == num.length()){
            if(res == target){
                ans.push_back(expr);
            }
            return;
        }
        for(int i = index; i<num.length(); i++){
            if(i > index && num[index] == '0') break;
            string part = num.substr(index, i - index + 1);
            long curr = stol(part);

            if(index == 0){
                dfs(i+1, curr, curr, part, num, target, ans);
            } else {

            // add
            dfs(i+1, res+curr, curr, expr + "+" + part, num, target, ans);

            // sub
            dfs(i+1, res-curr, -curr, expr + "-" + part, num, target, ans);

            // multiply
            dfs(i+1, res - prev + (prev * curr), prev * curr, expr + "*" + part, num, target, ans); }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(0, 0, 0, "", num, target, ans);
        return ans;
    }
};