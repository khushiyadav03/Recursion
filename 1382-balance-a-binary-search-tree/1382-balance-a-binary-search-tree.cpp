/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode* build(vector<int>& ans, int left, int right){
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = build(ans, left, mid-1);
        root->right = build(ans, mid+1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inord;
        inorder(root, inord);
        return build(inord, 0, inord.size() - 1);
    }
};