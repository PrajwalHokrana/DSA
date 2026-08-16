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
    TreeNode* helper(vector<int>& preorder, int& preIdx, int left, int right, unordered_map<int, int>& postMap) {
        if (left > right || preIdx >= preorder.size()) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx++]);

        // If this subtree only had one node, it has no children to split
        if (left == right) return root;

        // The next preorder element is the root of the left subtree
        int leftChildPostIdx = postMap[preorder[preIdx]];

        // Subtree bounds in postorder:
        // Left subtree spans [left, leftChildPostIdx]
        // Right subtree spans [leftChildPostIdx + 1, right - 1]
        root->left = helper(preorder, preIdx, left, leftChildPostIdx, postMap);
        root->right = helper(preorder, preIdx, leftChildPostIdx + 1, right - 1, postMap);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx = 0;
        unordered_map<int, int> postMap;
        
        for (int i = 0; i < postorder.size(); i++) {
            postMap[postorder[i]] = i;
        }

        return helper(preorder, preIdx, 0, postorder.size() - 1, postMap);
    }
};