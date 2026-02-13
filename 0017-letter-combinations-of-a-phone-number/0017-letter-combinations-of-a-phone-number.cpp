class Solution {
public:
    void solve(int index, string &digits, string &curr, vector<string> &ans, vector<string> &mapping) {

        if (index == digits.length()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mapping[digit];

        for (int i = 0; i < letters.length(); i++) {
            curr.push_back(letters[i]);
            solve(index + 1, digits, curr, ans, mapping);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty()) return ans;

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string curr = "";
        solve(0, digits, curr, ans, mapping);

        return ans;
    }
};
