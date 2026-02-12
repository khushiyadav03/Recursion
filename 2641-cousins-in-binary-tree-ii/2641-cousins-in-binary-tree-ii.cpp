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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return NULL;

        vector<long long> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        // First BFS → store level sums
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levelSum.push_back(sum);
        }

        // Second BFS → replace values
        q.push(root);
        root->val = 0;
        int level = 0;

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                long long siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left) {
                    node->left->val = levelSum[level + 1] - siblingSum;
                    q.push(node->left);
                }

                if (node->right) {
                    node->right->val = levelSum[level + 1] - siblingSum;
                    q.push(node->right);
                }
            }

            level++;
        }

        return root;
    }
};
