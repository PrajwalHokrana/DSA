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
    bool leftAndRightCheck(TreeNode* leftPart, TreeNode* rightPart) {
        if (!leftPart && !rightPart)
            return true;
        if (!leftPart || !rightPart)
            return false;
        if (leftPart->val != rightPart->val)
            return false;

        return leftAndRightCheck(leftPart->left, rightPart->right) &&
               leftAndRightCheck(leftPart->right, rightPart->left);
    }
    bool isSymmetric(TreeNode* root) {
        return leftAndRightCheck(root->left, root->right);
    }
};