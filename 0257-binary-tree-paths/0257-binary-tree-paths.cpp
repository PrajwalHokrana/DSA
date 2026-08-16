/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void paths(TreeNode* root, string str, vector<string>& ans) {
        if (!root) return;

        str += to_string(root->val);

        // Leaf node: store complete path and terminate this branch
        if (!root->left && !root->right) {
            ans.push_back(str);
            return;
        }

        // Internal node: append arrow and explore non-null children
        str += "->";
        if (root->left) paths(root->left, str, ans);
        if (root->right) paths(root->right, str, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        
        paths(root, "", ans);
        return ans;
    }
};