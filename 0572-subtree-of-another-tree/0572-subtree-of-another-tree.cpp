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
    // Helper function from LC 100: checks if two trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base cases
        if (!root) return false;

        // 1. Check if the current tree matches subRoot
        if (isSameTree(root, subRoot)) return true;

        // 2. If not, check left or right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};