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
    TreeNode* helper(vector<int>& postorder, int& postIdx, int left, int right, unordered_map<int, int>& inMap) {
        if (left > right) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = inMap[rootVal];

        // Must construct right subtree first in reverse postorder
        root->right = helper(postorder, postIdx, inIdx + 1, right, inMap);
        root->left = helper(postorder, postIdx, left, inIdx - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;
        unordered_map<int, int> inMap;
        
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return helper(postorder, postIdx, 0, inorder.size() - 1, inMap);
    }
};