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
private:
    int count = 0;

    void dfs(TreeNode* root, int maxSoFar) {
        if (!root) return;

        if (root->val >= maxSoFar) {
            count++;
            maxSoFar = root->val;
        }

        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }

public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val);
        return count;
    }
};