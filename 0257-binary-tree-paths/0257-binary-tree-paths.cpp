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
    void paths(vector<string>& ans, TreeNode* root, string str) {
        if (root->left==NULL && root->right==NULL) {
            str += to_string(root->val);
            ans.push_back(str);
            return;
        }

        str += to_string(root->val) + "->";

        if (root->left)
            paths(ans, root->left, str);
        if (root->right)
            paths(ans, root->right, str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str;
        paths(ans,root,str);
        return ans;
    }
};