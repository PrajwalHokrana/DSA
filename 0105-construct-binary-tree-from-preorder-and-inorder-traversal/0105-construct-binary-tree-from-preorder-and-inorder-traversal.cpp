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
    TreeNode* helper(const vector<int>& preorder, int& preIdx, int left, int right, unordered_map<int, int>& inMap) {
        if (left > right) {
            return nullptr;
        }

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = inMap[rootVal];

        // Build left subtree first (matches Preorder: Root -> Left -> Right)
        root->left = helper(preorder, preIdx, left, inIdx - 1, inMap);
        root->right = helper(preorder, preIdx, inIdx + 1, right, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        int preIdx = 0;
        return helper(preorder, preIdx, 0, inorder.size() - 1, inMap);
    }
};