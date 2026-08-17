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
    void helper(vector<vector<int>>& ans, vector<int> path, TreeNode* root, int targetSum) {
        if(!root) return;
        if (!root->left && !root->right) {
            if (targetSum - root->val == 0) {
                path.push_back(root->val);
                ans.push_back(path);
            }
            return;
        }

        path.push_back(root->val);
        helper(ans, path, root->left, targetSum - root->val);
        helper(ans, path, root->right, targetSum - root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        if(root==NULL)return ans;

        helper(ans,path,root,targetSum);

        return ans;
    }
};