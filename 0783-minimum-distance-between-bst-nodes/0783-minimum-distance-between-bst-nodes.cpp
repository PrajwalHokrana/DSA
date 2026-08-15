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
    void inorder(TreeNode* root, int& prev, int& diff) {
        if (root == nullptr)
            return;

        // 1. Visit Left Subtree
        inorder(root->left, prev, diff);

        // 2. Process Current Node
        if (prev != -1) {
            diff = min(diff, root->val - prev);
        }
        prev = root->val; // Update prev to current node's value

        // 3. Visit Right Subtree
        inorder(root->right, prev, diff);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int diff = INT_MAX;

        inorder(root, prev, diff);

        return diff;
    }
};