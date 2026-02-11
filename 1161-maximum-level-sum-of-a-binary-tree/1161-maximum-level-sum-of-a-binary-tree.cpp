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
    int maxLevelSum(TreeNode* root) {
        if(!root) return -1;
        queue<TreeNode*> q;
        q.push(root);

        long long maxSum = LLONG_MIN;
        int maxlevel = 1;
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            int levelSum = 0;
            level++;

            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(levelSum > maxSum){
                maxSum = levelSum;
                maxlevel = level;
            }
        }

        return maxlevel;
    }
};