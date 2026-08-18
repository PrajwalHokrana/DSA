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
    int runningSum = 0;

    void reverseInorder(TreeNode* root) {
        if (!root)
            return;

        // 1. Visit Right Subtree (larger values first)
        reverseInorder(root->right);

        // 2. Process Current Node
        runningSum += root->val;
        root->val = runningSum;

        // 3. Visit Left Subtree (smaller values last)
        reverseInorder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        runningSum = 0;
        reverseInorder(root);
        return root;
    }
};