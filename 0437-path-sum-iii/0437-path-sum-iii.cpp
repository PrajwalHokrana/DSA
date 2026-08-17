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
    int countPathsFrom(TreeNode* root, long long targetSum) {
        if (!root) return 0;

        int count = 0;
        if (root->val == targetSum) {
            count++;
        }

        count += countPathsFrom(root->left, targetSum - root->val);
        count += countPathsFrom(root->right, targetSum - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        // Paths starting at root + all paths in left and right subtrees
        return countPathsFrom(root, targetSum) + 
               pathSum(root->left, targetSum) + 
               pathSum(root->right, targetSum);
    }
};